//*******************************************************************************
//
//    Date: 9 April 2021
//    File name: packetCapture.cpp
//
//   Description: This application program uses the libpcap network API 
//                to display a list of network hosts.
//
//*******************************************************************************

#include <iostream>
#include <pcap.h>
using namespace std;

//*******************************************************************************

void beginProcessing ( );
void displayPacket ( const u_char * packet, struct pcap_pkthdr header );
void handlePackets ( u_char * kwargs, const struct pcap_pkthdr * header,
                     const u_char * body );
void displayHosts ( );
void readPackets ( );

//*******************************************************************************

int main ( )
{
    beginProcessing ( );

    return 0;
}

//*******************************************************************************

void beginProcessing ( )
{
    const int EXIT_FLAG = -1;
    int userChoice = 0;

    do
    {
        readPackets ( );
        displayHosts ( );
        cin >> userChoice;
    } 
    while ( userChoice != -1 );
}

//*******************************************************************************

void displayPacket ( const u_char * packet, struct pcap_pkthdr header )
{
    cout << "Length: " << header.len << endl;
}

//*******************************************************************************

void handlePackets ( u_char * kwargs, const struct pcap_pkthdr * header,
                     const u_char * body )
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

void readPackets ( )
{
    const int ERROR_BUFFER_SIZE = 81;

    struct bpf_program firstFilter;
    char expression[] = "port 23";
    bpf_u_int32 subnet;
    struct pcap_pkthdr firstHeader;
    char *networkDevice;
    char errorMsg[ERROR_BUFFER_SIZE];
    pcap_t *sessionHandle;
    pcap_if_t *alldevs;
    pcap_if_t **alldevs_ptr = &alldevs;

    if (pcap_findalldevs(alldevs_ptr, errorMsg) == -1)
    {
        cout << "Error finding network interface: " << errorMsg << endl;
    }
    else
    {
        networkDevice = (*alldevs_ptr)->name;
    }

    if (networkDevice == nullptr)
    {
        cout << "Error: " << errorMsg << endl;
    }
    else
    {
        sessionHandle = pcap_open_live(networkDevice, ERROR_BUFFER_SIZE, 1,
                                       1000, errorMsg);
    }

    if ( pcap_compile(sessionHandle, &firstFilter, expression, 0, subnet) == -1)
    {
        cout << "Error: pcap compile" << endl;
    }

    if (pcap_setfilter(sessionHandle, &firstFilter) == -1)
    {
        cout << "Error: pcap filter" << endl;
    }

    pcap_loop(sessionHandle, 0, handlePackets, nullptr);
    pcap_close(sessionHandle);
}

//*******************************************************************************
