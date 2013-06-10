#include "openfolderaction.h"
#include <stdlib.h>

OpenFolderAction::OpenFolderAction()
{
    m_handables.push_back("dosierujo");
}

void OpenFolderAction::handle(Node* n_node)
{
    std::string t_command="dolphin " + n_node->content().str();
    system(t_command.c_str());
}
