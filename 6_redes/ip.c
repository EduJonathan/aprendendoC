#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    const char *desired_ifname = "wlan0"; // Mude para o nome da sua interface, como "wlan0" ou "en0"

    struct ifaddrs *ifaddr = NULL, *ifa = NULL;
    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        return 1;
    }

    char ip_str[INET_ADDRSTRLEN] = {0};
    int found = 0;

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
            continue;

        if (strcmp(ifa->ifa_name, desired_ifname) == 0 && ifa->ifa_addr->sa_family == AF_INET)
        {

            struct sockaddr_in *sa = (struct sockaddr_in *)ifa->ifa_addr;
            if (inet_ntop(AF_INET, &sa->sin_addr, ip_str, sizeof(ip_str)) != NULL)
            {
                found = 1;
                break; // Achou o primeiro IPv4 → pode parar (ou continue se quiser todos)
            }
        }
    }

    freeifaddrs(ifaddr);

    if (found)
    {
        printf("Interface '%s' → IPv4: %s\n", desired_ifname, ip_str);
    }
    else
    {
        printf("Nenhum endereço IPv4 encontrado para a interface '%s'\n", desired_ifname);
    }

    return 0;
}
