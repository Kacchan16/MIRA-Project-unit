#include <fw/Unit.h>
using namespace mira;
namespace tutorials {
class FloatProducer : public Unit
{
MIRA_OBJECT(FloatProducer)
public:
    FloatProducer();
    template<typename Reflector>
    void reflect(Reflector& r)
    {
        MIRA_REFLECT_BASE(r, Unit);
    }
protected:
    virtual void initialize();
    virtual void process(const Timer& timer);
private:
     Channel<float> mFloatChannel;
     float mValue;
};
FloatProducer::FloatProducer() : Unit(Duration::milliseconds(100))
{
}
void FloatProducer::initialize()
{
    mFloatChannel = publish<float>("FloatChannel");
    mValue = 0.0f;
}
void FloatProducer::process(const Timer& timer)
{
    mValue += 1.0f;
    mFloatChannel.post(mValue);
    std::cout << "FloatProducer: " << mValue << std::endl;
}
}
MIRA_CLASS_SERIALIZATION(tutorials::FloatProducer, mira::Unit );