//
// Created by Nicholas Simpson on 28/02/2022.
//

#ifndef MODELTWO_SETTINGS_H
#define MODELTWO_SETTINGS_H

extern bool set_template_indestructible;
extern bool set_monomer_count_is_constant; //Only useful if no_rebinding = true
extern bool set_no_rebinding;
extern double set_seed;
extern double set_k;//Polymerisation rate
extern double set_k0;//Binding rate
extern double set_G_bb;//Backbone forming free energy
extern double set_G_spec;//Specific bond forming free energy
extern double set_G_gen;//Generic bond forming free energy
extern double set_M_eff;//Effective concentration of monomers in zipping
extern int set_monomers_family_zero;
extern int set_monomers_family_one;
extern int set_template_length;
extern int set_transition_limit;


#endif //MODELTWO_SETTINGS_H
