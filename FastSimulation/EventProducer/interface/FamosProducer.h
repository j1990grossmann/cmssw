#ifndef FastSimulation_EventProducer_FamosProducer_H
#define FastSimulation_EventProducer_FamosProducer_H

#include "FWCore/Framework/interface/stream/EDProducer.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h" // future obsolete
#include "SimDataFormats/CrossingFrame/interface/CrossingFrame.h"    // obsolete

class FamosManager;
class ParameterSet;
class Event;
class EventSetup;

namespace HepMC { 
  class GenEvent;
}

class FamosProducer : public edm::stream::EDProducer <>
{

 public:

  explicit FamosProducer(edm::ParameterSet const & p);
  virtual ~FamosProducer();
  virtual void beginRun(edm::Run const& run, const edm::EventSetup & es) override;
  virtual void produce(edm::Event & e, const edm::EventSetup & c) override;

 private:

  FamosManager * famosManager_;
  HepMC::GenEvent * evt_;
  bool simulateMuons;

  
  // token for hepmc from signal event
  edm::EDGetTokenT<edm::HepMCProduct> sourceToken;
  // token for hepmc from pu
  edm::EDGetTokenT<edm::HepMCProduct> puToken;
};

#endif
