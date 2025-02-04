#include "intf.h"

void get_mac(char *intf, unsigned char *mac)
{
    int fd;
    struct ifreq ifr;
    fd=socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family=AF_INET;
    strncpy(ifr.ifr_name, intf, IF_NAMESIZE-1);
    ioctl(fd, SIOCGIFHWADDR, &ifr);
    close(fd);
    strcpy(mac, ifr.ifr_hwaddr.sa_data);
}

void get_ip(char *intf, unsigned char *ip)
{
    int fd;
    struct ifreq ifr;
    fd=socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family=AF_INET;
    strncpy(ifr.ifr_name, intf, IF_NAMESIZE-1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    strcpy(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}