#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	public : 
		void set_index(int i);
		void add_contact();
		void search_contact();
	private :
		int now_idx;
		Contact contacts[8];
};

#endif