/*
 A relation is essentially a list of all tuples of arguments for which
 the associated predicate evaluates to true.
 
 Every relation has a time value for the first argument, with the
 actual objects following. So intersect(5, 1, 2) means that at time 5,
 object 1 intersects object 2. Therefore, a single relation spans the
 entire duration of an experiment. This convention makes the FOIL
 algorithm more straightforward to implement.
 
 In most cases, a predicate will evaluate to true for some set of
 objects for long stretches of time. For example, two objects may
 intersect for the entire duration of an experiment. A data structure
 optimization was made to exploit this fact: Instead of storing a
 relation as a set of tuples, it stored as a map whose keys are the
 tails of the tuples starting from the 2nd argument, and whose values
 are the sets of times for which the predicate was true for the keys.
 For example, the set of tuples:
 
 (0, A, B)
 (1, A, B)
 (2, A, B)
 (2, C, D)
 (3, C, D)
 
 would be stored as
 
 {
   (A, B) -> [ 0, 1, 2 ],
   (C, D) -> [ 2, 3 ]
 }
 
 Note that I'm using A, B, C, D for clarity. The actual tuples in the
 relation would all be integers. This optimization cuts down on memory
 as well as the cost of operations like intersection.
*/

#ifndef RELATION_H
#define RELATION_H

#include <iostream>
#include <vector>
#include <map>
#include "common.h"
#include "serializable.h"

class relation : public serializable {
public:
	/*
	class const_iterator {
	public:
		const_iterator &operator=(const const_iterator &i);
		const tuple &operator*() const;
		
	private:
		const_iterator(const relation &r);
		
		const relation &r;
		tuple t;
		tuple_map::const_iterator i;
		std::set<int>::const_iterator j;
	};
	*/
	
	relation();
	relation(int n);
	relation(const relation &r);
	relation(int n, const std::vector<tuple> &t);
	
	void add(const tuple &t);
	void add(int i, int n);  // convenience for arity = 2
	void add(int i, const tuple &t);
	void del(const tuple &t);
	void del(int i, int n);  // convenience for arity = 2
	void del(int i, const tuple &t);
	bool has(const tuple &t) const;
	void slice(const tuple &inds, relation &out) const;
	bool operator==(const relation &r) const;
	relation &operator=(const relation &r);
	void expand(const relation &r, const tuple &match1, const tuple &match2, const tuple &extend);
	void count_expansion(const relation  &r, const tuple &match1, const tuple &match2, int &matched, int &new_size) const;
	void intersect(const tuple &inds, const relation &r);
	void subtract(const tuple &inds, const relation &r);
	void difference(const relation &r, relation &out) const;
	void at_pos(int n, std::set<int> &elems) const;
	void drop_first(std::set<tuple> &out) const;
	void clear();
	void reset(int new_arity);
	void match(const tuple &pattern, relation &r) const;
	void filter(const tuple &pattern);
	void sample(int k, relation &s) const;
	void serialize(std::ostream &os) const;
	void unserialize(std::istream &is);
	
	int size() const { return sz; }
	int arity() const { return arty; }
	bool empty() const { return sz == 0; }

	template<typename C>
	void dump(C &out) const {
		std::insert_iterator<C> ins(out, out.end());
		tuple_map::const_iterator i;
		tuple t(arty);
		for (i = tuples.begin(); i != tuples.end(); ++i) {
			copy(i->first.begin(), i->first.end(), t.begin() + 1);
			std::set<int>::const_iterator j;
			for (j = i->second.begin(); j != i->second.end(); ++j) {
				t[0] = *j;
				ins = t;
			}
		}
	}
	
private:
	void update_size();
	
	typedef std::map<tuple, std::set<int> > tuple_map;

	int sz, arty;
	tuple_map tuples;
	
	friend std::ostream &operator<<(std::ostream &os, const relation &r);
};

typedef std::map<std::string, relation> relation_table;

std::ostream &operator<<(std::ostream &os, const relation &r);
std::ostream &operator<<(std::ostream &os, const relation_table &t);

#endif
