#include <vector>
#include <iostream>
#include "Destination.h"
#include <climits>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;

CityNetwork::CityNetwork(string * In) {
    ifstream File1(In[0]);
    if(File1.is_open()) {
        string line1;
        while (getline(File1, line1)) {
            addCity(line1);  }   }
    else {
        cout<<"File 1 not found"<<endl;
        In=nullptr;
        return;     }
    ifstream File2(In[1]);
    if(File2.is_open()) {
        string readLine2;
        string City1, City2, dist;
        int distance;
        while(getline(File2, readLine2)) {
            stringstream line2(readLine2);
            getline(line2, City1, ',');
            getline(line2, City2,',');
            getline(line2, dist);
            stringstream ss(dist);  ss>>distance; 
            addEdge(City1, City2, distance);    }   }
    else {
        cout<<"File 2 not found"<<endl;
        In=nullptr;
        return;     }
    ifstream File3(In[2]);
    if(File3.is_open()) {
        string Hotspot, inCost, inRank, City;
        int cost, rank;
        while(getline(File3, readLine)) {
            stringstream line(readLine);
            getline(line, City);
            getline(line, Hotspot, ',');
            getline(line, inCost, ',');    stringstream sc(inCost); sc>>cost;
            getline(line, inRank);         stringstream sr(inRank); sr>>rank;
            addHotSpot(City, Hotspot, rank, cost);
    }   }
    else {
        cout<<"File 3 not found"<<endl;
        In=nullptr;
        return;  
    } 
}

void CityNetwork::addHotSpot(string City, string name, int rank, int cost) {
    city*newHot=search(City);
    int i=0;
    HotSpot*walker=newHot->hotHead;
    HotSpot * temp= new HotSpot;
    if(walker==nullptr) {
        temp->HotSpotName=name;
        temp->cost=cost;
        temp->stars=rank;
        temp->prev=nullptr;
        temp->next=nullptr;
        newHot->hotHead=temp;
        temp=nullptr;
        return;
    }
    while(walker->next != nullptr) {
        walker=newHot->next;
    }
        temp->HotSpotName=name;
        temp->cost=cost;
        temp->stars=rank;
        temp->prev=walker;
        temp->next=nullptr;
        walker->next=temp;
        temp=nullptr;
        return;
}
HotSpot * CityNetwork::deleteHotSpot(HotSpot*byeBye) {
    if(byeBye->next!=nullptr) {
        return deleteHotSpot(byeBye->next);
    }
    delete byeBye;
    byeBye=nullptr;
    return nullptr;
}

CityNetwork::~CityNetwork() {
    for(int i=0;i<Cities.size();i++) {
        if(Cities[i]->hotHead!=nullptr) {
            deleteHotSpot(hotHead);
        }
    }
}
void CityNetwork::citySearch(string name) {
    city*temp=search(name);
    if(temp==nullptr) { cout<<"City not Found"<<endl; return;}
}
city * search(string name) {
    for(int i=0; i<Cities.size();i++) {
        if(Cities[i]->CityName==name) return Cities[i];
    }
    return nullptr;
}

void CityNetwork::addEdge(string City1, string City2, int distance) {
    for(int i=0; i<Cities.size(); i++){
        if(Cities[i].CityName==City1){
            for(int j=0; j<Cities.size(); j++){
                if(Cities[j].CityName==City2 && i!=j){
                    adjCity ac;
                    ac.c = &Cities[j];
                    ac.distance = distance;
                    Cities[i].adj.push_back(ac);
                    return;
}   }   }   }   }

void CityNetwork::addCity(string CityName) {
    bool found=false;
    for(int i=0; i<Cities.size(); i++){
        if(Cities[i].CityName == CityName){
            found=true;
            cout<<Cities[i].CityName<<" Already exists."<<endl;
    }   }
    if(found==false) {
        city v;
        v= city(CityName);
        Cities.push_back(v);
}   }

void CityNetwork::displayEdges(){
    string separator = "-->";
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < Cities.size(); i++){
        cout<<Cities[i].CityName<<"-->";
        for(int j = 0; j < Cities[i].adj.size(); j++){
            cout<<Cities[i].adj[j].c->CityName<<"***";
        }
        cout<<endl;
    }
}
