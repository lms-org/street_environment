#ifndef LMS_STREET_ENVIRONMENT_CROSSING_H
#define LMS_STREET_ENVIRONMENT_CROSSING_H
#include "obstacle.h"
#include "lms/time.h"

namespace street_environment{
/**
 * @brief A dynamic entity can be the vehicle itself but also every other
 * moving obstacle.
 */
class Crossing:public Obstacle
{
private:
    bool m_blocked;
    lms::Time m_startStop;
    float m_stopTime;

public:
    bool startStop(){
        if(m_startStop == lms::Time::ZERO){
            m_startStop = lms::Time::now();
            return true;
        }
        return false;
    }
    bool hasToStop() const{
        if(m_startStop != lms::Time::ZERO){
            return m_startStop.since().toFloat() < m_stopTime; //Time that we have to wait for an obstacle magic number
        }
        return true;
    }

    lms::Time stopTime(){
        return m_startStop;
    }

    Crossing():m_blocked(true),m_startStop(lms::Time::ZERO),m_stopTime(2){
    }

    static constexpr int TYPE = 2;

    virtual bool match(const Crossing &obj) const{
        if(!Obstacle::match(obj)){
            return false;
        }
        //TODO
        return false;
    }


    int getType() const override{
       return TYPE;
    }


    void blocked(bool blocked){
        m_blocked = blocked;
    }

    bool blocked() const{
        return m_blocked;
    }

    // cereal implementation
    #ifdef USE_CEREAL
        //get default interface for datamanager
        CEREAL_SERIALIZATION()

        template<class Archive>
        void serialize(Archive & archive) {
            archive (
                cereal::base_class<street_environment::Obstacle>(this),
                m_blocked, m_startStop);
        }
    #endif

};

typedef std::shared_ptr<Crossing> CrossingPtr;
}//street_environment
#endif //LMS_STREET_ENVIRONMENT_CROSSING_H
