//*******************************************************************************
//    Name: Kyle McColgan
//    Date: 16 February 2021
//    File name: packetCapture.cpp
//
//   Description: This application program displays a list of network hosts.
//
//*******************************************************************************

#include <iostream>
#include <pcap.h>
using namespace std;

//*******************************************************************************

int main ( )
{
    const int ERROR_BUFFER_SIZE = 81;
    struct bpf_program firstFilter;
    char expression [ ] = "port 23";
    bpf_u_int32 mask;

    char * networkDevice;
    char errorMsg [ERROR_BUFFER_SIZE];

    pcap_t * sessionHandle;

    networkDevice = pcap_findalldev ( errorMsg );

    if ( networkDevice == nullptr )
    {
        cout << "Error: " << errorMsg << endl;
    }

    sessionHandle = pcap_open_live ( networkDevice, ERROR_BUFFER_SIZE, 1,
                                     1000, errorMsg );

    if ( sessionHandle == nullptr ) 
    {
        cout << "Error: " << errorMsg << endl;
    }

    if ( pcap_compile(sessionHandle, &firstFilter, expression, 0 mask ) == -1)
    {
        cout << "Error: " << errorMsg << endl;
    }

    pcap_close ( sessionHandle );

    return 0;
}

//*******************************************************************************

void displayHosts ( )
{
    cout << "IP address    " << "    Data sent    " 
         << "    Data received    " << endl;
    cout << "=========================================" << endl;


    cout << "=========================================" << endl;
}

//*******************************************************************************

void startSniffing ( )
{

}

//*******************************************************************************
