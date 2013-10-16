#ifndef MEMORYLOADER_H
#define MEMORYLOADER_H

class MemoryLoader
{
    public:

        MemoryLoader(Network& n_network, LinkGraph& n_links);

    protected:

        Network& n_network;
        LinkGraph& m_links;
};

#endif // MEMORYLOADER_H
