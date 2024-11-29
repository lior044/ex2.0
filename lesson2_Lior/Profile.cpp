#include "Profile.hpp";
#include <vector>
#include <iostream>
/*	User _Owner;
	Page _Page;
	UserList _UserList;*/
void Profile::init(User owner) {
	_Owner = owner;
	_Page.init();
	_Friends.init();
}
void Profile::clear() {
	_Friends.clear();
	_Owner.clear();
	_Page.clearPage();

}
User Profile::getOwner() const {
	return _Owner;
}
std::string Profile::getPage() const {
	std::string page;
	page = "Status: " + _Page.getStatus() + "\n";
	page = page + "*******************\n*******************\n";
	page = page + _Page.getPosts();
	return page;
}
std::string Profile::getFriends() const {
	UserNode* temp = new UserNode;
	std::string Friend_List = "";
	temp = _Friends.get_first();
	if (temp != nullptr) {
		do {
			if (Friend_List == "") {
				Friend_List = temp->get_data().getUserName();
				temp = temp->get_next();
			}
			else {
				Friend_List = Friend_List + "\," + temp->get_data().getUserName();
				temp = temp->get_next();
			}
		} while (temp->get_next() != nullptr);
		Friend_List = Friend_List + "\," + temp->get_data().getUserName(); //add the last friend
	}
	else {
		Friend_List = "you have no Frinds";
	}

	delete temp;
	return Friend_List;
}
std::string Profile::getFriendsWithSameNameLength() const {
	UserNode* temp = new UserNode;
	std::string Friend_List = "";
	std::string name_to_cmp;
	name_to_cmp = _Owner.getUserName();
	int length_of_my_name = 0;
	length_of_my_name = name_to_cmp.length();
	int length_of_friends_name;


	temp = _Friends.get_first();
	if (temp != nullptr) {
		while (temp->get_next() != nullptr) {
			length_of_friends_name = temp->get_data().getUserName().length();
			if (length_of_my_name == length_of_friends_name) {
				if (Friend_List == "") {
					Friend_List = temp->get_data().getUserName();
				}
				else {
					Friend_List = Friend_List + "\," + temp->get_data().getUserName();
				}

			}
			temp = temp->get_next();
		}
	}
	else {
		Friend_List = "You have no frinds with the same length name as you";
	}

	delete temp;
	return Friend_List;
}
void Profile::setStatus(std::string new_ststus) {
	_Page.setStatus(new_ststus);
}
void Profile::addPostToProfilePage(std::string post) {
	_Page.addLineToPosts(post);
}
void Profile::addFriend(User friend_to_add) {
	_Friends.add(friend_to_add);
}
void Profile::changeAllWordsInStatus(std::string word) {

}
void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word) {

}