#ifndef FT_IRC_CHANNEL_HPP
#define FT_IRC_CHANNEL_HPP

#include <iostream>
#include <vector>

class User;

class Channel {
private:
	std::vector<User *> users;
	std::string channelName;
	std::string topic;
	User *userOperator;

public:
	Channel(std::string chName);

	virtual             ~Channel();

	std::string getChannelName(void);

	bool ifUserExist(std::string userName);

	bool isEmpty();

	void setUser(User *user);

	void sendMessageToChannel(std::string msg, User *sender);

	void removeUser(std::string userName);

	void setTopic(std::string newTopic);

	std::string setGetTopic(std::string newTopic);

	std::string getTopic();

	void setOperators(User *operatorr);

	User *isOperator(User *user);
};

#endif