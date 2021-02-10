//*******************************************************************************
//    Name: Kyle McColgan
//    Date: 9 February 2021
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
    char * device;
    char errorMsg [81];

    device = pcap_lookupdev ( errorMsg );

    if ( device == nullptr )
    {
        cout << "Error: " << errorMsg << endl;
    }

    return 0;
}
