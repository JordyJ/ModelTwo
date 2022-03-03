//
// Created by Nicholas Simpson on 03/02/2022.
//

#include <iostream>
#include <vector>
#include <random>
#include "Connection.h"
#include "Polymer.h"
#include "UnconnectedNeighbours.h"
#include "ConnectedNeighbours.h"
#include "FreeSite.h"

using namespace std;

#ifndef MODELTWO_CONGLOMERATE_H
#define MODELTWO_CONGLOMERATE_H


class Conglomerate {
public:
    bool backbone_indestructable;
    //Identifies the conglomerate
    int index;
    //Defines all connections in this conglomerate
    vector<Connection *> connections;

    //Holds polymers in conglomerate for easy access
    vector<Polymer *> polymers;

    //Holds connections specific to polymers for easy access
    //If innermost vector is length 0 then there is no connection
    vector<vector<vector<Connection *>>> polymer_connections; //polymer<monomer<connection>>

    //Holds the free sites of each family
    vector<vector<FreeSite *>> available_free_sites_list; //family<free site list>

    //Holds the head copy-template connections that can break
    vector<Connection *> head_unbinding_list;

    //Holds the tail copy-template connections that can break
    vector<Connection *> tail_unbinding_list;

    //Holds the head copy-template connections that can form
    vector<Connection *> head_binding_list;

    //Holds the tail copy-template connections that can form
    vector<Connection *> tail_binding_list;

    //Holds the neighbours that can polymerise together
    vector<UnconnectedNeighbours *> unconnected_neighbours_list;

    //Holds the neighbours that can polymerise together
    vector<ConnectedNeighbours *> connected_neighbours_list;

    //Initialisation
    Conglomerate(vector<Connection *> con, bool bb); //When a conglomerate splits in two, we use the separated list of connections to form the conglomerate
    Conglomerate(Polymer * polymer, bool bb); //When a single polymer is a conglomerate, there are no connections to be used

    //Update
    void updateConglomerate();
    void updatePolymersInConglomerate();
    void updateAvailableFreeSites();
    void updateUnbindingLists();
    void updateBindingLists();
    void checkBindingValidity(int polymer, int monomer, int direction);
    void updateNeighboursBindingList();
    void updateNeighboursUnbindingList();

    //Choose Transitions
    void addConnection(Conglomerate * conglomerate_being_joined, Connection * new_connection);
    vector<Conglomerate *> chooseHeadUnbinding(int chosen_bond);
    vector<Conglomerate *> chooseTailUnbinding(int chosen_bond);
    vector<Conglomerate *> checkSeparation(Connection * removed_connection);
    vector<Polymer *> getTree(Polymer * p, vector<Polymer *> connected_polymers);
    void chooseHeadBinding(int chosen_bond);
    void chooseTailBinding(int chosen_bond);
    Polymer * chooseNeighboursBind(int chosen_bond);
    Polymer * chooseNeighboursUnbind(int chosen_bond);

};


#endif //MODELTWO_CONGLOMERATE_H
