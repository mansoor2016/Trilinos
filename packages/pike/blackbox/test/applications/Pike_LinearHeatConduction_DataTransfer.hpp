#ifndef PIKE_LINEAR_HEAT_CONDUCTION_DATA_TRANSFER_HPP
#define PIKE_LINEAR_HEAT_CONDUCTION_DATA_TRANSFER_HPP

#include "Pike_DataTransfer.hpp"
#include "Teuchos_RCP.hpp"
#include "Teuchos_Assert.hpp"

namespace Teuchos {
  template<typename > class Comm;
}

namespace pike_test {

  class LinearHeatConductionModelEvaluator;

  /** \brief Simple example of data transfer for unit testing

      This object can operate in two modes:

      1. TRANSFER_T: Transfers the temperature T_right from source application to T_left of the target application

      2. TRANSFER_Q: Transfers the heat flux from the source application to any number of target applications

      See any book on heat transfer.  For example, "Transport
      Phenomena" by Bird, Stewart and Lightfoot, 2nd edition, section
      10.6 "Heat Conduction Through Composite Walls", pages 303-305.
   */
  class LinearHeatConductionDataTransfer : public pike::DataTransfer {

  public:

    enum Mode {
      TRANSFER_T,
      TRANSFER_Q
    };

    LinearHeatConductionDataTransfer(const Teuchos::RCP<Teuchos::Comm<int> >& comm,
				     const std::string name,
				     const Mode mode);

    //@{ DataTransfer derived methods
    
    std::string name() const;

    bool doTransfer(const pike::Solver& solver);

    bool transferSucceeded() const;

    //@}

    void setSource(const Teuchos::RCP<pike_test::LinearHeatConductionModelEvaluator>& source);

    void addTarget(const Teuchos::RCP<pike_test::LinearHeatConductionModelEvaluator>& target);

  private:
    Teuchos::RCP<Teuchos::Comm<int> > comm_;
    std::string name_;
    Mode mode_;
    Teuchos::RCP<pike_test::LinearHeatConductionModelEvaluator> source_;
    std::vector<Teuchos::RCP<pike_test::LinearHeatConductionModelEvaluator> > targets_;
  };

  /** \brief non-member ctor
      \relates LinearHeatConductionModelEvaluator
  */
  Teuchos::RCP<pike_test::LinearHeatConductionDataTransfer> 
  linearHeatConductionDataTransfer(Teuchos::RCP<Teuchos::Comm<int> > comm,
				   std::string name,
				   pike_test::LinearHeatConductionDataTransfer::Mode mode);
  

}

#endif
