#include <iostream>
#include <string.h>
#include<fstream>
using namespace std;
class Date
{
    int jour;
    int mois;
    int annee;
public:
    Date();
    Date(int,int,int);
    int getjour();
    int getmois();
    int getannee();
    void setjour(int);
    void setmois(int);
    void setannee(int);
    bool cntr_date(int,int,int);
    friend istream& operator>>(istream&,Date&);
    friend ostream& operator<<(ostream&,Date&);

};
class personne
{
    protected:
    string nom;
    string prenom;
    string CIN;
    Date date_de_naissance;
    public :
    personne();
    personne(string,string,string,Date);
    string getnom(){return nom;}
    string getpernom(){return prenom;}
    string getcin(){return CIN;}
    Date getdate_de_naissance(){return date_de_naissance;}
    virtual void saisirpersonne();
    virtual void choix();
    virtual ~personne();
};
class client : public personne
{
    protected:
    bool bus;
    string destination;
    public:
    client();
    client(personne,bool,string);
    bool get_bus(){return bus;}
    string getdestination(){return destination;}
    void saisirclient();
    void reserver();
    void reserver_bus();
    ~client();
    friend istream& operator>>(istream&,client&);
    friend ostream& operator<<(ostream&,client&);
};
class chauffeur : public personne
{
    protected :
    string num_permis;
    string Agence;
    public:
    chauffeur();
    chauffeur(personne,string,string);
    string getnumpermis(){return num_permis;}
    string getagence(){return Agence;}
    void saisirchauffeur();
    ~chauffeur();
    friend istream& operator>>(istream&,chauffeur&);
    friend ostream& operator<<(ostream&,chauffeur&);
};
class guide : public personne
{
    protected:
    string specialite;
    string agence;
    string destination;
    public:
    guide();
    guide(personne,string,string,string);
    string getspecialite(){return specialite;}
    string getagence(){return agence;}
    string getdestination(){return destination;}
    void saisirguide();
    ~guide();
    friend istream& operator>>(istream&,guide&);
    friend ostream& operator<<(ostream&,guide&);
};
class responsable : public personne
{
    protected:
    string agence;
    string reponsabilite;
    public:
    responsable();
    responsable(personne,string,string);
    void saisirreponsable();
    void ajouter_client(fstream&);
    void ajouter_chauffeur(fstream&);
    void ajouter_guide(fstream&);
    void afficher_les_clients(fstream&);
    void afficher_les_chauffeurs(fstream&);
    void afficher_les_guides(fstream&);
    void supprimer_client();
    ~responsable();
};


string verificationcin()
{
    string s;
    cin>>s;
    if(s.size() != 8)
    {
        cout<<"svp donnez un numero d'une carte d'identité nationale valide "<<endl;
        cin>>s;
    }
    else
    {
        return s;
    }
    return 0;
}
istream& operator>>(istream& inc,Date& d )
{
    cout<<"le jour est"<<endl;
    inc>>d.jour;
    cout<<"le mois est"<<endl;
    inc>>d.mois;
    cout<<"l'annee est"<<endl;
    inc>>d.annee;
    return inc;
};
ostream& operator<<(ostream& out,Date& d)
{
    out<<d.jour<<"/"<<d.mois<<"/"<<d.annee;
    return out;
};
istream& operator>>(istream& inc,client& c)
{
    cout<<"les coordonees du client"<<endl;
    c.saisirpersonne();
    cout<<"donner la destination"<<endl;
    inc>>c.destination;
    cout<<"est ce qu'il va aller avec une bus?"<<endl;
    inc>>c.bus;
    return inc;
}
ostream& operator<<(ostream& out,client& c)
{
    cout<<"les cordonnees du client sont :"<<endl;
    out<<c.getnom()<<" ";
    out<<c.getpernom()<<" ";
    out<<c.getcin()<<" ";
    out<<c.getdate_de_naissance().getjour()<<"/"<<c.getdate_de_naissance().getmois()<<"/"<<c.getdate_de_naissance().getannee()<<" ";
    out<<c.get_bus()<<" ";
    out<<c.getdestination()<<endl;
    return out;
}
istream& operator>>(istream& inc,chauffeur& c)
{
    cout<<"les coordonees du chauffeur"<<endl;
    c.saisirpersonne();
    cout<<"donner le num permis"<<endl;
    inc>>c.num_permis;
    cout<<"quelle est l'agence"<<endl;
    inc>>c.Agence;
    return inc;
}
ostream& operator<<(ostream& out,chauffeur& c)
{
    cout<<"les cordonnees du chauffeur sont :"<<endl;
    out<<c.getnom()<<" ";
    out<<c.getpernom()<<" ";
    out<<c.getcin()<<" ";
    out<<c.getdate_de_naissance().getjour()<<"/"<<c.getdate_de_naissance().getmois()<<"/"<<c.getdate_de_naissance().getannee()<<" ";
    out<<c.getnumpermis()<<" ";
    out<<c.getagence()<<endl;
    return out;
}
istream& operator>>(istream& inc,guide& g)
{
    cout<<"les coordonees du guide"<<endl;
    g.saisirpersonne();
    cout<<"donner la specialite"<<endl;
    inc>>g.specialite;
    cout<<"donner l'agence"<<endl;
    inc>>g.agence;
    cout<<"donner la destination"<<endl;
    inc>>g.destination;
    return inc;
}
ostream& operator<<(ostream& out,guide& c)
{
    cout<<"les cordonnees du guide sont :"<<endl;
    out<<c.getnom()<<" ";
    out<<c.getpernom()<<" ";
    out<<c.getcin()<<" ";
    out<<c.getdate_de_naissance().getjour()<<"/"<<c.getdate_de_naissance().getmois()<<"/"<<c.getdate_de_naissance().getannee()<<" ";
    out<<c.getspecialite()<<" ";
    out<<c.getagence()<<" ";
    out<<c.getdestination()<<endl;
    return out;
}
string verificationpermis()
{
    string s;
    cin>>s;
    if((s.size() != 9) && (s[2]!='/'))
    {
        cout<<"svp donnez un numero permis valid"<<endl;
        cin>>s;
    }
    else
    {
        return s;
    }
    return 0;
}

