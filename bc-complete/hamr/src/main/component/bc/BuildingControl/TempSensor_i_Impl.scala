// #Sireum

package bc.BuildingControl

import org.sireum._
import bc._

// the contents of this file will not be overwritten
@record class TempSensor_i_Impl (val api : TempSensor_i_Bridge.Api) extends TempSensor_i {

  override def initialise(): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.setcurrentTemp(BuildingControl.Temperature_i.empty())
    api.sendtempChanged()
  }

  override def timeTriggered(): Unit = {
    // example override of timeTriggered
  }

  override def activate(): Unit = {
    // example override of activate
  }

  override def deactivate(): Unit = {
    // example override of deactivate
  }

  override def finalise(): Unit = {
    // example override of finalise
  }

  override def recover(): Unit = {
    // example override of recover
  }
}
