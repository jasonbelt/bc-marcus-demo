// #Sireum

package bc.BuildingControl

import org.sireum._
import bc._

// the contents of this file will not be overwritten
@record class Fan_i_Impl (val api : Fan_i_Bridge.Api) extends Fan_i {

  override def initialise(): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    val apiUsage_fanCmd: Option[BuildingControl.FanCmd.Type] = api.getfanCmd()
    api.sendfanAck(BuildingControl.FanAck.byOrdinal(0).get)
  }

  override def handlefanCmd(value : BuildingControl.FanCmd.Type): Unit = {
    api.logInfo("example handlefanCmd implementation")
    api.logInfo(s"received ${value}")
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
