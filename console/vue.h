#ifndef VUE_H
#define VUE_H
#include "observer.h"

class Game;

/*!
 * \brief Observateur console de money::Coin.
 *
 * Cette classe implémente concrètement le classe abstraite
 * nvs::Observer. Ses instances s'attachent à une et une seule
 * pièce de monnaie. Elles se contentent d'injecter leur sujet
 * d'observation, le money::Coin qu'elles observent, dans le
 * flux en sortie standard std::cout.
 */
class Vue  : public Observer
{
    /*! \brief Le sujet observé. */
    Game * subject_;

  public:

    /*!
     * \brief Constructeur.
     *
     * Le constructeur attache l'observateur en cours de construction
     * à la money::Coin fournie en argument. En fin de constructon,
     * l'observateur se met à jour.
     *
     * \param observable L'adresse du game observée.
     */
    Vue(Game * observable);

    /*!
     * \brief Destructeur.
     *
     * Lors de le destruction de l'observateur, il doit se détacher
     * de son sujet d'observation.
     */
    virtual ~Vue();

    /*!
     * \brief Mise à jour de l'observateur.
     *
     * Si subject est bien l'adresse de la pièce de monnaie
     * observée, l'observateur injecte celle-ci dans le flux
     * associé à la sortie standard, sinon, il ne se passe rien.
     *
     * \param subject Le nvs::Subject qui notifie un changement
     *                d'état.
     */
    virtual void update(const Observable * subject ) override;

};

#endif // VUE_H
