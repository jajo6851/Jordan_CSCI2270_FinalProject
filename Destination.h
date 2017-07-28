#ifndef DESTINATION_H
#define DESTINATION_H

struct city;

struct HotSpot {
    int cost;
    int stars;
    std::string HotSpotName;
    HotSpot * next;
    HotSpot * prev;
};

struct adjCity{
    city *c;
    int distance;
};

struct city{
  std::string CityName;
    bool visited;
    int traveled;
    city *previous;
    HotSpot *hotHead;
  std::vector<adjCity> adj;
  city() {};
  city(std::string initName) {
      CityName=initName;
      previous= nullptr;
      visited=false;
      traveled =0;
      hotHead= nullptr;
    }
};

class CityNetwork {
    public:
        CityNetwork(std::string * In);
        ~CityNetwork();
        void addEdge(std::string City1, std::string City2, int distance);
        void addCity(std::string CityName);
        void addHotSpot(std::string City, std::string name, int rank, int cost);
        void displayEdges();
        void citySearch(std::string name);
        void shortestPath(std::string City1, std::string City2);
    protected:
    private:
        std::vector<city> Cities;
        city * search(std::string name);
};
#endif // DESTINATION_H
