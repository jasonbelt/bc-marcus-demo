package bc.BuildingControl

import art.{ArtNative_Ext, Empty}
import bc._
import org.sireum._

// the contents of this file will not be overwritten
class BuildingControlDemo_i_Instance_tcp_fan_Test extends BridgeTestSuite[Fan_i_Bridge](Arch.BuildingControlDemo_i_Instance_tcp_fan) {
  test("Example Unit Test"){
    executeTest()
  }

  //////////////////////
  // HELPER FUNCTIONS //
  //////////////////////

  // setter for in EventDataPort
  def put_fanCmd(value : BuildingControl.FanCmd.Type): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.api.fanCmd_Id, BuildingControl.FanCmd_Payload(value))
  }

  // getter for out EventDataPort
  def get_fanAck(): Option[BuildingControl.FanAck.Type] = {
    val value: Option[BuildingControl.FanAck.Type] = get_fanAck_payload() match {
      case Some(BuildingControl.FanAck_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port fanAck.  Expecting 'BuildingControl.FanAck_Payload' but received ${v}") 
      case _ => None[BuildingControl.FanAck.Type]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_fanAck_payload(): Option[BuildingControl.FanAck_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.api.fanAck_Id).asInstanceOf[Option[BuildingControl.FanAck_Payload]]
  }

  def getComponent(): Fan_i_Impl = {
    return bridge.entryPoints.asInstanceOf[Fan_i_Bridge.EntryPoints].component
  }
}
