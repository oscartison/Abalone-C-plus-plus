#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "observer.h"

/*!
 * \brief abstract Class that defines an observable class
 *
 * an observable class is a class that will notify his observers
 * that a change was
 */
#include <set>

class Observer;

/*!
 * \brief Classe de base de tout "sujet d'observation".
 *
 * Classe dont dérive toute source d'événement (ou "sujet d'observation")
 * du modèle de conception "Observateur / SujetDObservation".
 *
 * \sa Observer.
 */
class Observable {

public :

    /*!
     * \brief Destructeur virtuel par défaut car utilisation polymorphique.
     */
    virtual ~Observable() = default;

    /*!
     * \brief Constructeur par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observable(const Observable &) = default;

    /*!
     * \brief Constructeur par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observable(Observable &&) = default;

    /*!
     * \brief Opérateur d'assignation par recopie par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observable & operator=(const Observable &) = default;

    /*!
     * \brief Opérateur d'assignation par déplacement par défaut.
     *
     * Le destructeur virtuel par défaut a des effets en cascade.
     *
     * \see http://stackoverflow.com/q/33957037
     * \see http://scottmeyers.blogspot.de/2014/03/a-concern-about-rule-of-zero.html
     * \see https://blog.feabhas.com/2015/11/becoming-a-rule-of-zero-hero/
     */
    Observable & operator=(Observable &&) = default;

    /*!
     * \brief Méthode permettant à un observateur de s'enregistrer comme
     * écouteur du sujet d'observation.
     *
     * \param observer un pointeur vers le candidat observateur.
     */
    virtual void registerObserver(Observer * observer) final;

    /*!
     * \brief Méthode permettant à un observateur de se retirer de la liste
     * des écouteurs patentés du sujet d'observation.
     *
     * \param observer l'adresse de l'observateur désintéressé.
     */
    virtual void unregisterObserver(Observer * observer) final;

protected :

    /*!
     * \brief Constructeur protégé pour éviter l'instanciation
     *        hors héritage.
     */
    Observable() = default;

    /*!
     * \brief Méthode qui se charge de prévenir les observateurs d'un
     * changement d'état du sujet d'observation, en invoquant leur
     * méthode Observer::update().
     *
     * \sa Observer::update(const Subject *).
     */
    virtual void notifyObservers() const final;

protected :

    /*!
     * \brief L'ensemble d'observateurs enregistrés.
     */
    std::set<Observer *> observers_ { };

};

#endif
