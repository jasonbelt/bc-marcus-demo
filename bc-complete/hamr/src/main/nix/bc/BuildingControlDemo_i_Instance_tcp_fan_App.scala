// #Sireum

package bc

import org.sireum._
import art._

// This file was auto-generated.  Do not edit

object BuildingControlDemo_i_Instance_tcp_fan_App extends App {

  val entryPoints: Bridge.EntryPoints = Arch.BuildingControlDemo_i_Instance_tcp_fan.entryPoints
  val appPortId: Art.PortId = IPCPorts.BuildingControlDemo_i_Instance_tcp_fan_App
  val appPortIdOpt: Option[Art.PortId] = Some(appPortId)
  val fanCmdPortId: Art.PortId = Arch.BuildingControlDemo_i_Instance_tcp_fan.fanCmd.id
  val fanCmdPortIdOpt: Option[Art.PortId] = Some(fanCmdPortId)

  def initialiseArchitecture(seed: Z): Unit = {
    Platform.initialise(seed, appPortIdOpt)
    Platform.initialise(seed, fanCmdPortIdOpt)

    Art.run(Arch.ad)
  }

  def initialise(): Unit = {
    entryPoints.initialise()
  }

  def compute(): Unit = {
    var dispatch = F
    Platform.receiveAsync(fanCmdPortIdOpt) match {
      case Some((_, v: BuildingControl.FanCmd_Payload)) => ArtNix.updateData(fanCmdPortId, v); dispatch = T
      case Some((_, v)) => halt(s"Unexpected payload on port fanCmd.  Expecting something of type BuildingControl.FanCmd_Payload but received ${v}")
      case None() => // do nothing
    }
    if (dispatch) {
      entryPoints.compute()
      Process.sleep(1000)
    } else {
      Process.sleep(10)
    }
  }

  def finalise(): Unit = {
    entryPoints.finalise()
  }

  def main(args: ISZ[String]): Z = {

    val seed: Z = if (args.size == z"1") {
      val n = Z(args(0)).get
      if (n == z"0") 1 else n
    } else {
      1
    }

    initialiseArchitecture(seed)

    Platform.receive(appPortIdOpt) // pause after setting up component

    initialise()

    Platform.receive(appPortIdOpt) // pause after component init

    println("BuildingControlDemo_i_Instance_tcp_fan_App starting ...")

    ArtNix.eventDispatch()

    var terminated = F
    while (!terminated) {
      val termOpt = Platform.receiveAsync(appPortIdOpt)
      if (termOpt.isEmpty) {
        compute()
      } else {
        terminated = T
      }
    }
    exit()

    return 0
  }

  def exit(): Unit = {
    finalise()
    Platform.finalise()
  }

  override def atExit(): Unit = {
    exit()
  }
}