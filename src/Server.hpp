//
// Created by OUT-Podovalov-PG on 26.09.2021.
//

#ifndef FT_IRC_SERVER_HPP
#define FT_IRC_SERVER_HPP

#include <string>
#include <sys/poll.h>
#include <vector>
#include "User.hpp"

class Server {
private:
	int socketFd;
	const std::string * host;
	const std::string & port;
	const std::string & password;
	std::vector<pollfd> fds;
	std::vector<User *> users;

public:
	Server(const std::string * host, const std::string & port, const std::string & password);
	void init();

	[[noreturn]] void start();
//	void stop();
	virtual ~Server();
	void acceptProcess();
	void recvMessage(User * user);
	void sendMessage(User * user);
	User *findUserByName(std::string userName);
//	Command *findCommandByName(std::string commandName); нужна map
	std::vector<std::string> setArgs(std::string argString);



};

#endif //FT_IRC_SERVER_HPP
