#include "vue.h"
#include "game.h"
#include <iostream>

Vue::Vue(Game * subject) :
    subject_ { subject }
{
    subject_->registerObserver(this);
    update(subject_);
}

Vue::~Vue()
{
    subject_->unregisterObserver(this);   // essayer sans...
}

void Vue::update(const Observable * subject)
{
    if (subject != subject_) return;

    std::cout  << *subject_ << std::endl;
}
