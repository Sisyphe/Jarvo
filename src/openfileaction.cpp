#include "openfileaction.h"
#include <stdlib.h>
#include <iostream>

OpenFileAction::OpenFileAction()
{
    m_handables.push_back("dosiero");
}

void OpenFileAction::handle(ThingNode* n_node)
{
    std::string t_command=std::string("xdg-open ") + n_node->content().str();
    system(t_command.c_str());
}
