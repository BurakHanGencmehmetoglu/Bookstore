#include "SoftCopy.h"




SoftCopy::SoftCopy(int ISBN, double price, int startPage, int endPage) : Book(ISBN, price) {
    ISBN=ISBN;
    price=price;
	this->startPage = startPage;
	this->endPage = endPage;
	this->numberOfPages = (endPage - startPage) + 1;
	this->firstHalf = NULL;
	this->secondHalf = NULL;
	this->pageContent = "";
}





SoftCopy::~SoftCopy() {
	if (firstHalf != NULL)
		delete firstHalf;
	if (secondHalf != NULL)
		delete secondHalf;
}





Book* SoftCopy::Clone() const {
        SoftCopy* clone=new SoftCopy(ISBN,price,startPage,endPage);
	    clone->pageContent = pageContent;
	    clone->next=next;
        SoftCopy* temp=firstHalf;
        SoftCopy* temp2=secondHalf;
        vector<SoftCopy*> s1; 
        vector<SoftCopy*> s2;
        vector<SoftCopy*> s3;
        if (temp!=NULL)
        {
            s1.push_back(temp);
            while (!s1.empty()) 
            {    
                SoftCopy* curr = s1[s1.size()-1]; 
                s1.pop_back(); 
                if (curr->firstHalf) 
                    s1.push_back(curr->firstHalf); 
                if (curr->secondHalf) 
                    s1.push_back(curr->secondHalf); 
                else if (!curr->firstHalf && !curr->secondHalf) 
                    s2.push_back(curr); 
            }
        }
        if (temp2!=NULL)
        {
            s3.push_back(temp2);
            while (!s3.empty()) 
            {    
                SoftCopy* curr = s3[s3.size()-1]; 
                s3.pop_back(); 
                if (curr->firstHalf) 
                    s3.push_back(curr->firstHalf); 
                if (curr->secondHalf) 
                    s3.push_back(curr->secondHalf); 
                else if (!curr->firstHalf && !curr->secondHalf) 
                    s2.push_back(curr); 
            }
        }
        for (int i=0;i<s2.size();i++)
        {
            clone->UploadPage(s2[i]->pageContent,s2[i]->startPage);
        }
        return clone;
}    






SoftCopy::SoftCopy(const SoftCopy& rhs) {
	    ISBN = rhs.GetISBN();
        price = rhs.GetPrice();
	    startPage = rhs.startPage;
        endPage = rhs.endPage;
        next=rhs.GetNext();
        numberOfPages = (endPage - startPage) + 1;
	    firstHalf = NULL;
	    secondHalf = NULL;
	    pageContent = rhs.pageContent;
        SoftCopy* temp=rhs.firstHalf;
        SoftCopy* temp2=rhs.secondHalf;
        vector<SoftCopy*> s1; 
        vector<SoftCopy*> s2;
        vector<SoftCopy*> s3;
        if (temp!=NULL)
        {
            s1.push_back(temp);
            while (!s1.empty()) 
            {    
                SoftCopy* curr = s1[s1.size()-1]; 
                s1.pop_back(); 
                if (curr->firstHalf) 
                    s1.push_back(curr->firstHalf); 
                if (curr->secondHalf) 
                    s1.push_back(curr->secondHalf); 
                else if (!curr->firstHalf && !curr->secondHalf) 
                    s2.push_back(curr); 
            }
        }
        if (temp2!=NULL)
        {
            s3.push_back(temp2);
            while (!s3.empty()) 
            {    
                SoftCopy* curr = s3[s3.size()-1]; 
                s3.pop_back(); 
                if (curr->firstHalf) 
                    s3.push_back(curr->firstHalf); 
                if (curr->secondHalf) 
                    s3.push_back(curr->secondHalf); 
                else if (!curr->firstHalf && !curr->secondHalf) 
                    s2.push_back(curr); 
            }
        }
        for (int i=0;i<s2.size();i++)
        {
            UploadPage(s2[i]->pageContent,s2[i]->startPage);
        }
}





SoftCopy& SoftCopy::operator=(const SoftCopy& rhs) {
    if (this!=&rhs)
    {
        if (firstHalf != NULL){delete firstHalf;}
	    if (secondHalf != NULL){delete secondHalf;}
		next=rhs.GetNext();
		ISBN=rhs.GetISBN();
		price=rhs.GetPrice();
	    startPage = rhs.startPage;
        endPage = rhs.endPage;
        numberOfPages = (endPage - startPage) + 1;
        firstHalf=NULL;
        secondHalf=NULL;
        SoftCopy* temp=rhs.firstHalf;
        SoftCopy* temp2=rhs.secondHalf;
        vector<SoftCopy*> s1; 
        vector<SoftCopy*> s2;
        vector<SoftCopy*> s3;
        if (temp!=NULL)
        {
            s1.push_back(temp);
            while (!s1.empty()) 
            {    
                SoftCopy* curr = s1[s1.size()-1]; 
                s1.pop_back(); 
                if (curr->firstHalf) 
                    s1.push_back(curr->firstHalf); 
                if (curr->secondHalf) 
                    s1.push_back(curr->secondHalf); 
                else if (!curr->firstHalf && !curr->secondHalf) 
                    s2.push_back(curr); 
            }
        }
        if (temp2!=NULL)
        {
            s3.push_back(temp2);
            while (!s3.empty()) 
            {    
                SoftCopy* curr = s3[s3.size()-1]; 
                s3.pop_back(); 
                if (curr->firstHalf) 
                    s3.push_back(curr->firstHalf); 
                if (curr->secondHalf) 
                    s3.push_back(curr->secondHalf); 
                else if (!curr->firstHalf && !curr->secondHalf) 
                    s2.push_back(curr); 
            }
        }
        for (int i=0;i<s2.size();i++)
        {
            UploadPage(s2[i]->pageContent,s2[i]->startPage);
        }
    }
    return *this;
}






SoftCopy& SoftCopy::operator+(const SoftCopy& rhs) const {
        SoftCopy* obj= new SoftCopy(ISBN,price,startPage,endPage);
        obj->pageContent=pageContent;
        obj->next=next;
        SoftCopy* temp=(SoftCopy *) this;
        SoftCopy* temp2=(SoftCopy *) &rhs;
        vector<SoftCopy*> s1; 
        vector<SoftCopy*> s2;
        vector<SoftCopy*> s3;
        if (temp!=NULL)
        {
            s1.push_back(temp);
            while (!s1.empty()) 
            {    
                SoftCopy* curr = s1[s1.size()-1]; 
                s1.pop_back(); 
                if (curr->firstHalf!=NULL){
                    s1.push_back(curr->firstHalf);
                }
                if (curr->secondHalf!=NULL){ 
                    s1.push_back(curr->secondHalf);
                }
                else if (curr->firstHalf==NULL && curr->secondHalf==NULL){ 
                    s2.push_back(curr); 
                }
            }
        }
        if (temp2!=NULL)
        {
            s3.push_back(temp2);
            while (!s3.empty()) 
            {    
                SoftCopy* curr = s3[s3.size()-1]; 
                s3.pop_back(); 
                if (curr->firstHalf!=NULL) { 
                    s3.push_back(curr->firstHalf);
                }
                if (curr->secondHalf!=NULL) { 
                    s3.push_back(curr->secondHalf);
                }
                else if (curr->firstHalf==NULL && curr->secondHalf==NULL) { 
                    s2.push_back(curr); 
                }
            }
        }
        for (int i=0;i<s2.size();i++)
        {
            obj->UploadPage(s2[i]->pageContent,s2[i]->startPage);
        }   
        return *obj;
}





void SoftCopy::Discount() {
    double fiyat=price*(75./100);
    price=fiyat;
}





void SoftCopy :: UploadPage(string content,int number) {
    SoftCopy* temp=this;
	while(temp->numberOfPages>1) 
	{
	    int ortanokta = (temp->startPage + temp->endPage)/2;
	    if (number<=ortanokta) {
	        if (temp->firstHalf==NULL) {
	            temp->firstHalf = new SoftCopy(ISBN, price, temp->startPage, ortanokta);
	        }
	        temp=temp->firstHalf;
	    }
	    else if (number>ortanokta) {
	        if (temp->secondHalf==NULL) {
	            temp->secondHalf = new SoftCopy(ISBN, price, ortanokta+1, temp->endPage);
	        }
	        temp=temp->secondHalf;
	    }
	}
	temp->pageContent=content;
}







string SoftCopy::Display(int from, int to) const {
    string content="";
    SoftCopy* temp=(SoftCopy*)this;
    vector<SoftCopy*> s1; 
    vector<SoftCopy*> s2;
    vector<SoftCopy*> s3;
    if (temp!=NULL)
    {
        s1.push_back(temp);
        while (!s1.empty()) 
        {    
            SoftCopy* curr = s1[s1.size()-1]; 
            s1.pop_back();
            if (curr->firstHalf != NULL){
                
                s1.push_back(curr->firstHalf);
                
            } 
            if (curr->secondHalf != NULL) {
                
                s1.push_back(curr->secondHalf);
                
            }
            else if (curr->firstHalf==NULL && curr->secondHalf==NULL)
            {
                if (curr->startPage>=from && curr->startPage<= to)
                {
                        s2.push_back(curr);
                    
                }
            }    
        }
    }
    int i=s2.size()-1;
    for (;i>=0;i--)
    {
        content=content+s2[i]->pageContent+"\n";
    }
    return content.substr(0,content.length()-1);
}
        