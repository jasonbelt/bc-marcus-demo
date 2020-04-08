package bc.BuildingControl

import org.sireum._
import art._

object TempSensor_i_seL4Nix_Ext {
  def currentTemp_Send(d: DataContent): Unit = halt("stub")

  def tempChanged_Send(d: DataContent): Unit = halt("stub")
}
