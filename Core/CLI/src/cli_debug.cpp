/*------------------------------------------------------------------
                       set cli command

   @author Mazin Assanie

   @date 2007

------------------------------------------------------------------ */


#include "portability.h"

#include "cli_CommandLineInterface.h"
#include "cli_Commands.h"
#include "cli_Cli_enums.h"

#include "agent.h"
#include "debug.h"
#include "episodic_memory.h"
#include "misc.h"
#include "output_manager.h"
#include "output_settings.h"
#include "semantic_memory.h"
#include "sml_Names.h"
#include "sml_AgentSML.h"
#include "soar_instance.h"

using namespace cli;
using namespace sml;

bool CommandLineInterface::DoDebug(std::vector< std::string >* argv)
{

    agent* thisAgent = m_pAgentSML->GetSoarAgent();
    bool result = false;
    size_t numArgs = 0;
    std::ostringstream tempString;
    std::string err, sub_command;

    if (!argv)
    {
        Output_Manager* l_OutputManager = &Output_Manager::Get_OM();
        PrintCLIMessage_Header("Debug", 40);
        PrintCLIMessage_Section("Commands", 40);
        PrintCLIMessage_Justify("allocate [pool blocks]", "Allocates extra memory to a memory pool", 40);
        PrintCLIMessage_Justify("internal-symbols", "Prints symbol table", 40);
        PrintCLIMessage_Justify("port", "Prints listening port", 40);
        PrintCLIMessage_Section("Debug Database Storage", 40);
        PrintCLIMessage_Item("database:", l_OutputManager->m_params->database, 40);
        PrintCLIMessage_Item("append-database:", l_OutputManager->m_params->append_db, 40);
        PrintCLIMessage_Item("path:", l_OutputManager->m_params->path, 40);
        PrintCLIMessage_Section("Performance", 40);
        PrintCLIMessage_Item("lazy-commit:", l_OutputManager->m_params->lazy_commit, 40);
        PrintCLIMessage_Item("page-size:", l_OutputManager->m_params->page_size, 40);
        PrintCLIMessage_Item("cache-size:", l_OutputManager->m_params->cache_size, 40);
        PrintCLIMessage_Item("optimization:", l_OutputManager->m_params->opt, 40);
        PrintCLIMessage("");

        result = true;
        goto print_syntax;
    }

    numArgs = argv->size() - 1;
    sub_command = argv->front();

    if (numArgs == 1)
    {
        if (sub_command[0] == 'g')
        {
            std::string parameter_name = argv->at(1);
            soar_module::param* my_param = thisAgent->debug_params->get(parameter_name.c_str());
            if (!my_param)
            {
                tempString.str("");
                tempString << "Debug| Invalid parameter: " << parameter_name;
                SetError(tempString.str().c_str());
                goto print_syntax;
            }
            tempString.str("");
            tempString << "Debug| " << my_param->get_name() << " = " << my_param->get_string();
            PrintCLIMessage(&tempString);
            return true;
        }
        else if (sub_command[0] == 't')
        {
            std::string mode = argv->at(1);
            int debug_type;
            if (!from_string(debug_type, mode))
            {
                tempString.str("");
                tempString << "Debug | Invalid value: " << mode;
                SetError(tempString.str().c_str());
                goto print_syntax;
            }
            else
            {
                debug_test(debug_type);
                return true;
            }
        }
        else if (sub_command[0] == 'e')
        {
            std::string mode = argv->at(1);
            int debug_type;
            if (!from_string(debug_type, mode))
            {
                tempString.str("");
                tempString << "Debug | Invalid value: " << mode;
                SetError(tempString.str().c_str());
                goto print_syntax;
            }
            else
            {
                debug_trace_set(debug_type, true);
                return true;
            }
        }
        else if (sub_command[0] == 'd')
        {
            std::string mode = argv->at(1);
            int debug_type;
            if (!from_string(debug_type, mode))
            {
                tempString.str("");
                tempString << "Debug | Invalid value: " << mode;
                SetError(tempString.str().c_str());
                goto print_syntax;
            }
            else
            {
                debug_trace_set(debug_type, false);
                return true;
            }
        }
    }
    else if (numArgs == 2)
    {
        if (sub_command[0] == 'a')
        {
            int blocks = 0;
            if (!from_string(blocks, argv->at(2)))
            {
                return SetError("Expected an integer (number of blocks).");
            }

            if (blocks < 1)
            {
                return SetError("Expected a positive integer (number of blocks).");
            }

            return DoAllocate(argv->at(1), blocks);
        }
        else if (sub_command[0] == 's')
        {
            std::string parameter_name = argv->at(1);
            std::string parameter_value = argv->at(2);

            soar_module::param* my_param = thisAgent->debug_params->get(parameter_name.c_str());
            if (!my_param)
            {
                tempString.str("");
                tempString << "Debug| Invalid parameter: " << parameter_name;
                SetError(tempString.str().c_str());
                goto print_syntax;
            }
            if (!my_param->validate_string(parameter_value.c_str()))
            {
                tempString.str("");
                tempString << "Debug| Invalid value: " << parameter_value;
                SetError(tempString.str().c_str());
                goto print_syntax;
            }

            bool result = my_param->set_string(parameter_value.c_str());

            if (!result)
            {
                SetError("Debug| Could not set parameter!");
                goto print_syntax;
            }
            else
            {
                tempString << "Debug| " << my_param->get_name() << " = " << parameter_value.c_str();
                PrintCLIMessage(&tempString);
                return true;
            }
        }
        else if (sub_command[0] == 'p')
        {
            std::string database_name = argv->at(1);
            std::string table_name = argv->at(2);
            if (database_name[0] == 'e')
            {
                thisAgent->EpMem->epmem_db->print_table(table_name.c_str());
            }
            else if (database_name[0] == 's')
            {
                thisAgent->SMem->DB->print_table(table_name.c_str());
            }
            else
            {
                tempString.str("");
                tempString << "Debug | Invalid database parameter: " << sub_command << ".";
                SetError(tempString.str().c_str());
                goto print_syntax;
            }
        }
        else
        {
            tempString.str("");
            tempString << "Debug| Invalid command: " << sub_command << ".";
            SetError(tempString.str().c_str());
            goto print_syntax;
        }

        return result;
    }
    else if (numArgs == 0)
    {
        if (sub_command[0] == 'a')
        {
            return DoAllocate(std::string(), 0);
            return true;
        }
        if (sub_command[0] == 'i')
        {
            thisAgent->symbolManager->print_internal_symbols();
            return true;
        }
        else if (sub_command[0] == 'p')
        {

            int port = m_pKernelSML->GetListenerPort();

            if (m_RawOutput)
            {
                m_Result << port;
            }
            else
            {
                std::string temp;
                AppendArgTag(sml_Names::kParamPort, sml_Names::kTypeInt, to_string(port, temp));
            }            return true;
        }
        else
        {
            tempString.str("");
            tempString << "Debug| Invalid command: " << sub_command << ".";
            SetError(tempString.str().c_str());
            goto print_syntax;
        }

        return result;
    }

    tempString.str("");
    tempString << "Debug| Invalid number of parameters (" << numArgs << ") to command " << sub_command << ".";
    SetError(tempString.str().c_str());

print_syntax:

    PrintCLIMessage("\nSyntax: Debug [command]");
    return result;
}

/**
 * @brief A utility function to run the agent for a certain number of
 *        decision cycles.  Used so that consolidate can make sure it
 *        has the episodes it needs to do an issued experiment.  (i.e.
 *        just saves us the hassle of having to run
 *
 * @param thisAgent         Agent to run
 * @param run_count     Number of decision cycles to run for
 */
void CommandLineInterface::Run_DC(agent* thisAgent, int run_count)
{
    std::ostringstream tempString;
    tempString << "MemCon| Running for " << run_count << " decision cycles.\n";
    PrintCLIMessage(&tempString);
    cli::Options opt;
//    cli::OptionsData optionsData[] =
//    {
//        {'d', "decision",        cli::OPTARG_NONE},
//        {'e', "elaboration",    cli::OPTARG_NONE},
//        {'g', "goal",            cli::OPTARG_NONE},
//        {'i', "interleave",        cli::OPTARG_REQUIRED},
//        {'n', "noupdate",        cli::OPTARG_NONE},
//        {'o', "output",            cli::OPTARG_NONE},
//        {'p', "phase",            cli::OPTARG_NONE},
//        {'s', "self",            cli::OPTARG_NONE},
//        {'u', "update",            cli::OPTARG_NONE},
//        {0, 0, cli::OPTARG_NONE}
//    };

    cli::RunBitset options(0);
    DoRun(options, run_count, cli::RUN_INTERLEAVE_DEFAULT);

}
bool CommandLineInterface::DoAllocate(const std::string& pool, int blocks)
{
    if (pool.empty())
    {
        GetMemoryPoolStatistics(); // cli_stats.cpp
        return true;
    }

    agent* thisAgent = m_pAgentSML->GetSoarAgent();
    if (thisAgent->memoryManager->add_block_to_memory_pool_by_name(pool, blocks))
    {
        m_Result << pool << " blocks increased by " << blocks;
        return true;
    }

    SetError("Could not allocate memory.  Probably a bad pool name: " + pool);
    return false;
}
