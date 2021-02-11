//*******************************************************************************
//    Name: Kyle McColgan
//    Date: 10 February 2021
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


    char * networkDevice;
    char errorMsg [ERROR_BUFFER_SIZE];

    pcap_t * sessionHandle;

    networkDevice = pcap_lookupdev ( errorMsg );

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

    pcap_close ( sessionHandle );

    return 0;
}
