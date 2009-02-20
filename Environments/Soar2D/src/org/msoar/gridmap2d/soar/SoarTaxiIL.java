package org.msoar.gridmap2d.soar;

import org.msoar.gridmap2d.Direction;
import org.msoar.gridmap2d.Names;
import org.msoar.gridmap2d.Simulation;
import org.msoar.gridmap2d.map.TaxiMap;

import sml.Agent;
import sml.FloatElement;
import sml.Identifier;
import sml.IntElement;
import sml.StringElement;

class SoarTaxiIL {
	private Agent agent;
	private SelfIL self = new SelfIL();
	private ViewIL view = new ViewIL();
	private CellIL cell = new CellIL();
	
	SoarTaxiIL(Agent agent) {
		this.agent = agent;
	}

	void create() throws CommitException {
		self.create();
		view.create();
		cell.create();
		
		if (!agent.Commit()) {
			throw new CommitException();
		}
	}
	
	void update(boolean moved, int[] pos, TaxiMap map, int reward, int fuel) throws CommitException {
		self.update(moved, pos, map, reward, fuel);
		view.update(pos, map);
		cell.update(pos, map);
		
		if (!agent.Commit()) {
			throw new CommitException();
		}
	}
	
	void destroy() throws CommitException {
		self.destroy();
		view.destroy();
		cell.destroy();
		
		if (!agent.Commit()) {
			throw new CommitException();
		}
	}
	
	private class SelfIL {
		private class RandomIL {
			private FloatElement randomWME;

			private void create() {
				randomWME = agent.CreateFloatWME(selfWME, Names.kRandomID, Simulation.random.nextFloat());
			}
			
			private void update() {
				assert randomWME != null;
				
				// force blink
				this.destroy();
				this.create();
			}
			
			private void destroy() {
				agent.DestroyWME(randomWME);
				randomWME = null;
			}
		}
		
		private Identifier selfWME;
		private IntElement xWME;
		private IntElement yWME;
		private IntElement reward;
		private StringElement passenger;
		private StringElement destination;
		private IntElement fuel;
		
		private RandomIL random = new RandomIL();

		private void create() {
			selfWME = agent.CreateIdWME(agent.GetInputLink(), "self");

			Identifier position = agent.CreateIdWME(selfWME, "position");
			xWME = agent.CreateIntWME(position, Names.kXID, 0);
			yWME = agent.CreateIntWME(position, Names.kYID, 0);

			reward = agent.CreateIntWME(selfWME, "reward", 0);

			passenger = agent.CreateStringWME(selfWME, "passenger", "false");
			destination = null;

			fuel = agent.CreateIntWME(selfWME, "fuel", 0);

			random.create();
		}
	
		private void update(boolean moved, int[] pos, TaxiMap map, int reward, int fuel) {
			assert selfWME != null;

			if (moved) {
				agent.Update(xWME, pos[0]);
				agent.Update(yWME, map.size() - 1 - pos[1]);
			}
			
			// force blink
			agent.DestroyWME(this.reward);
			this.reward = agent.CreateIntWME(selfWME, "reward", reward);
			
			if (map.isPassengerCarried()) {
				agent.Update(passenger, "true");
				if (destination == null) {
					destination = agent.CreateStringWME(selfWME, "destination", map.getPassengerDestination());
				}
				
			} else {
				agent.Update(passenger, "false");
				if (destination != null) {
					agent.DestroyWME(destination);
					destination = null;
				}
			}

			agent.Update(this.fuel, fuel);

			random.update();
		}
		
		private void destroy() {
			agent.DestroyWME(selfWME);
			selfWME = null;
			random.destroy();
		}
	}
	
	private class ViewIL {
		private Identifier viewWME;
		private StringElement northType;
		private StringElement northWall;
		private StringElement northPassenger;
		private StringElement southType;
		private StringElement southWall;
		private StringElement southPassenger;
		private StringElement eastType;
		private StringElement eastWall;
		private StringElement eastPassenger;
		private StringElement westType;
		private StringElement westWall;
		private StringElement westPassenger;
		
		private void create() {
			viewWME = agent.CreateIdWME(agent.GetInputLink(), "view");

			Identifier north = agent.CreateIdWME(viewWME, "north");
			northType = agent.CreateStringWME(north, "type", "none");
			northPassenger = agent.CreateStringWME(north, "passenger", "false");
			northWall = agent.CreateStringWME(north, "wall", "false");
			
			Identifier south = agent.CreateIdWME(viewWME, "south");
			southType = agent.CreateStringWME(south, "type", "none");
			southPassenger = agent.CreateStringWME(south, "passenger", "false");
			southWall = agent.CreateStringWME(south, "wall", "false");

			Identifier east = agent.CreateIdWME(viewWME, "east");
			eastType = agent.CreateStringWME(east, "type", "none");
			eastPassenger = agent.CreateStringWME(east, "passenger", "false");
			eastWall = agent.CreateStringWME(east, "wall", "false");

			Identifier west = agent.CreateIdWME(viewWME, "west");
			westType = agent.CreateStringWME(west, "type", "none");
			westPassenger = agent.CreateStringWME(west, "passenger", "false");
			westWall = agent.CreateStringWME(west, "wall", "false");
		}
		
		private void update(int[] pos, TaxiMap map) {
			assert viewWME != null;
			
			updateView(pos, map, Direction.NORTH, northType, northPassenger, northWall);
			updateView(pos, map, Direction.SOUTH, southType, southPassenger, southWall);
			updateView(pos, map, Direction.EAST, eastType, eastPassenger, eastWall);
			updateView(pos, map, Direction.WEST, westType, westPassenger, westWall);

		}
		
		private void updateView(int [] pos, TaxiMap map, Direction direction, StringElement type, StringElement passenger, StringElement wall) {
			int [] tempLocation = Direction.translate(pos, direction, new int[2]);
			
			agent.Update(type, map.getStringType(tempLocation));
			
			if (map.isInBounds(tempLocation)) {
				if (map.getCell(tempLocation).getObject("passenger") != null) {
					agent.Update(passenger, "true");
				} else {
					agent.Update(passenger, "false");
				}
			} else {
				agent.Update(passenger, "false");
			}

			if (map.wall(pos, direction)) {
				agent.Update(wall, "true");
			} else {
				agent.Update(wall, "false");
			}
		}
		
		private void destroy() {
			agent.DestroyWME(viewWME);
			viewWME = null;
		}
	}
	
	private class CellIL {
		private Identifier cellWME;
		private StringElement cellType;
		private StringElement cellPassenger;
		
		private void create() {
			cellWME = agent.CreateIdWME(agent.GetInputLink(), "cell");
			cellType = agent.CreateStringWME(cellWME, "type", "none");
			cellPassenger = agent.CreateStringWME(cellWME, "passenger", "false");
		}
		
		private void update(int[] pos, TaxiMap map) {
			assert cellWME != null;
			
			agent.Update(cellType, map.getStringType(pos));
			
			if (map.getCell(pos).getObject("passenger") != null) {
				agent.Update(cellPassenger, "true");
			} else {
				agent.Update(cellPassenger, "false");
			}
		}
		
		private void destroy() {
			agent.DestroyWME(cellWME);
			cellWME = null;
		}
	}
}
