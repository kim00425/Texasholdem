#include<iostream>
#include<ctime>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netdb.h>
#include<fcntl.h>
#include<arpa/inet.h>

#include"card.h"
#include"Hand.hpp"
#include"Deck.hpp"
#include"Player.hpp"
#include"Game.hpp"
#include"Host.hpp"

#define PORT_NUM 3600

int main()
{
    int server;
    struct sockaddr_in server_addr;
    socklen_t sock_len=sizeof(server_addr);
    server=socket(AF_INET, SOCK_STREAM, 0);
    
    Player client_player;
    if(server==-1)
    {
        perror("Socket error!!");
        exit(1);
    }
    
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(PORT_NUM);
    
    if(bind(server, (struct sockaddr*)&server_addr, sock_len)==-1)
    {
        perror("Bind error!!");
        exit(1);
    }
    listen(server, 5);
    Game game;
    accept(server,(struct sockaddr*)&server_addr, &sock_len);
    recv(server, (Player*)&client_player, sizeof(Player),0);
    std::cout<<client_player.GetName()<<"님이 접속하셨습니다"<<std::endl;
    game=client_player;
    
    
    
}
