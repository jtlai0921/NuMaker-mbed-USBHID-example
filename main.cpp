#include "mbed.h"
#include "USBHID.h"
 
//We declare a USBHID device. Output/input reports have a length of 8 bytes
USBHID hid(8, 8);
 
//This report will contain data to be sent
HID_REPORT send_report;
HID_REPORT recv_report;
 
Serial pc(USBTX, USBRX);
 
int main(void) {
    send_report.length = 8;
 
    while (1) {
        //Fill the report
        for (int i = 0; i < send_report.length; i++) {
            send_report.data[i] = rand() & 0xff;
        }
            
        //Send the report
        hid.send(&send_report);
        
        //try to read a msg
        if(hid.readNB(&recv_report)) {
            pc.printf("recv: ");
            for(int i = 0; i < recv_report.length; i++) {
                pc.printf("%d ", recv_report.data[i]);
            }
            pc.printf("\r\n");
        }
        
        wait(0.1);
    }
}
