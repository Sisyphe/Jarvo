#include "openlink.h"
#include "openfileaction.h"
#include "openfolderaction.h"
#include "openprogramaction.h"

OpenLink::OpenLink(Brain& n_brain)
    :CommandLink(n_brain)
{
    m_verb="aperti";

    m_handlers.push_back(new OpenFileAction());
    m_handlers.push_back(new OpenFolderAction());
    m_handlers.push_back(new OpenProgramAction());

    searchNewHandlers();
}
