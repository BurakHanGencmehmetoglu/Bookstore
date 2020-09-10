#ifndef SOFTCOPY_H
#define SOFTCOPY_H

#include "Book.h"

class SoftCopy : public Book {

	private:
		int startPage, endPage;	/* id for the first page and last page, resp.
								   Note that there may not be any page uploaded
								   yet. */

		int numberOfPages;		

		string pageContent;		/* holds the string held by this current softcopy
		                           (not the ones held by its children). */

		SoftCopy* firstHalf;	/* Points to the child softcopy representing its
								   first half. */

		SoftCopy* secondHalf;	/* Points to the child softcopy representing its
								   second half. */

	public:
		/*********************************************************************
		*	Constructor
		*
		* The first @param is ISBN (id number) of the book
		* The second @param is price of the book
		* The third @param is the starting page id
		* The fourth @param is the ending page id
		* Set the "next" variable to NULL.
		*/
		SoftCopy(int, double, int, int);
		/*********************************************************************
		*	Copy Constructor
		*
		* All is deep copy except the pointer variable 'next'
		*/
		SoftCopy(const SoftCopy&);
		/*********************************************************************
		*	Assignment operator
		*
		*  All is deep copy except the pointer variable 'next'
		*/
		SoftCopy& operator=(const SoftCopy&);
		/*********************************************************************
		*	Operator Overload +
		*
		* Adds the pages given in the @param to this SoftCopy object.
		*/
		SoftCopy& operator+(const SoftCopy&) const;
		/*********************************************************************
		*	Clone
		*
		* @return pointer to a copy of this Book object
		*/
		Book* Clone() const;
		/*********************************************************************
		*	Discount
		*
		* Discounts the price of the book.
		* It applies 25% of discount. For example:
		  - If the price is 100 TL, the new price will be 75 TL.
		*/
		void Discount();
		/*********************************************************************
		*	UploadPage
		*
		* Constructs the page whose id is given in the second @param, then
		  Uploads the page content given in the first @param.
		*/
		void UploadPage(string, int);
		/*********************************************************************
		*	Display
		*
		* @return content of the pages in the given interval whose borders are
		  defined by the first and second @param.
		* For the output, combine the contents of different pages by pushing
		  a newline character '\n'.
		*/
		string Display(int from, int to) const;
		/*********************************************************************
		*	Destructor
		*/
		~SoftCopy();
		/*********************************************************************/
};

#endif
