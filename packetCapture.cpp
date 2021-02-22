//*******************************************************************************
//    Name: Kyle McColgan
//    Date: 22 February 2021
//    File name: packetCapture.cpp
//
//   Description: This application program displays a list of network hosts.
//
//*******************************************************************************

#include <iostream>
#include <pcap.h>
using namespace std;

//*******************************************************************************

void displayPacket ( const u_char * packet, struct pcap_pkthdr header );

void handlePackets (u_char * args, const struct pcap_pkthdr * header, 
                    const u_char * body );

void displayHosts ( );
void startSniffing ( );

//*******************************************************************************

int main ( )
{
    const int ERROR_BUFFER_SIZE = 81;
    struct bpf_program firstFilter;
    char expression [ ] = "port 23";
    bpf_u_int32 mask;
    bpf_u_int32 subnet;
    struct pcap_pkthdr firstHeader;
    const u_char * firstPacket;

    char * networkDevice;
    char errorMsg [ERROR_BUFFER_SIZE];

    pcap_t * sessionHandle;

    pcap_if_t * alldevs;
    pcap_if_t ** alldevs_ptr = &alldevs;

    if ( pcap_findalldevs ( alldevs_ptr, errorMsg ) == -1 )
    {
        cout << "Error finding network interface: " << errorMsg << endl;
    }
    else
    {
        networkDevice = (* alldevs_ptr)->name;
    }
    
    if ( networkDevice == nullptr )
    {
        cout << "Error: " << errorMsg << endl;
    }
    else
    {
        sessionHandle = pcap_open_live ( networkDevice, ERROR_BUFFER_SIZE, 1,
                                     1000, errorMsg );
    }
    
    if ( sessionHandle == nullptr ) 
    {
        cout << "Error: " << errorMsg << endl;
    }

    if ( pcap_compile(sessionHandle, &firstFilter, expression, 0, subnet ) == -1)
    {
        cout << "Error: pcap compile" << endl;
    }

    if ( pcap_setfilter ( sessionHandle, &firstFilter ) == -1 )
    {
        cout << "Error: pcap filter" << endl;
    }

    firstPacket = pcap_next ( sessionHandle, &firstHeader );

    pcap_loop ( sessionHandle, 0, handlePackets, nullptr );

    pcap_close ( sessionHandle );

    return 0;
}

//*******************************************************************************

void displayPacket ( const u_char * packet, struct pcap_pkthdr header )
{
    cout << "Length: " << header.len << endl;
}

//*******************************************************************************

void handlePackets (u_char * args, const struct pcap_pkthdr * header, const u_char * body )
{
    displayPacket(body, *header );
}

//*******************************************************************************

void displayHosts ( )
{
    cout << "IP address    |" << "    Data sent    |" 
         << "    Data received    " << endl;
    cout << "=========================================" << endl;


    cout << "=========================================" << endl;
}

//*******************************************************************************

void startSniffing ( )
{
    cout << "Begin listening..." << endl;

    cout << "Ending listening..." << endl;
}

//*******************************************************************************
