//
//  ParticleSystem.cpp
//  NOC_4_03_ParticleSystemClass
//
//  Created by Matthias Esterl on 7/4/13.
//
//

#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(ofPoint location, ofImage img_) {
    origin = location;
    img = img_;
}

void ParticleSystem::addParticle(){
    particles.push_back(new Particle(origin, img));
}

void ParticleSystem::update(){    
    for (int i = 0; i < particles.size(); i++){
        particles.at(i)->update();
        if(particles.at(i)->isDead()){
            cout << "Particle dead!" << endl;
            particles.erase(particles.begin() + i);
        }
    }
}

void ParticleSystem::display(){
    for (int i = 0; i < particles.size(); i++){
        particles.at(i)->display();
    }
}