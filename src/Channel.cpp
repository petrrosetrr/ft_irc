#include "Channel.hpp"

Channel::Channel(std::string chName) : channelName(chName) {
}

Channel::~Channel() {
}

std::string	Channel::getChannelName(void) {
	return channelName;
}

std::vector<User *> Channel::getUsers(void) {
	return users;
}

User*	Channel::getUser(std::string	userName) {
	for (std::vector<User*>::const_iterator i = users.begin(); i != users.end(); i++)
	{
		if ((*i)->getNickName() == userName)
			return (*i);
	}
	return nullptr;
}

bool	Channel::ifUserExist(std::string userName) {
	for (std::vector<User*>::const_iterator i = users.begin(); i != users.end(); i++)
	{
		if ((*i)->getNickName() == userName)
			return true;
	}
	return false;
}

void	Channel::setUser(User* user) {
	users.push_back(user);
}

void Channel::sendMessageToChannel(std::string msg, User *sender) {
	std::vector<User *>::const_iterator i;
	for (i = users.begin(); i != users.end(); i++)
	{
		if (*i != sender)
			(*i)->messageToUser(msg + "\r\n");
	}
}

//не знаю почему, но не видит поля с юзерами

void	 Channel::removeUser(std::string userName) {
	// int found = 0; пусть пока побудет
	for (std::vector<User *>::const_iterator i = users.begin(); i != users.end(); i++)
	{
		if ((*i)->getNickName() == userName)
			break;
		// found++; // тоже пусть пока побудет
	}
	// erase удаляет из вектора диапазон элементов начиная с found знакачивая длиной строки
	this->users.erase(users.begin() + i);
}
