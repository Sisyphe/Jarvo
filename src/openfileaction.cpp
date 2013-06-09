#include "openfileaction.h"
#include <stdlib.h>
#include <iostream>

OpenFileAction::OpenFileAction()
{
    m_handables.push_back("dosiero");
}

void OpenFileAction::handle(Node* n_node)
{
    std::string t_command=std::string("xdg-open ") + n_node->content().str();
    std::cout << t_command << std::endl;
    system(t_command.c_str());
}
