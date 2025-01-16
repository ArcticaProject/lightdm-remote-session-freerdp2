# LightDM (Arctica Greeter) Remote Logon: FreeRDP(2) #

Configuration for LightDM / Arctica Greeter to launch remote FreeRDP
sessions using FreeRDPv2/FreeRDPv3.

This code project was originally started by Canonical Ltd. and has been
adapted by various authors with the purpose of making Remote Logon
against RDP servers via Arctica Greeter (formerly known as Unity Greeter)
available on Ubuntu and non-Ubuntu systems alike.

## Installation

See https://github.com/ArcticaProject/ArcticaDocs/tree/master/ArcticaGreeter

## Configuration

For this Remote Logon Add-on to work, you have to populate

```
/etc/arctica-greeter/guest-session/skel/.config/freerdp/known_hosts2
```

with your RDP servers' host keys. Otherwise, logins will fail.

Alternatively, add the /cert-ignore option to the set of FREERDP_OPTIONS
in /etc/default/lightdm-remote-session-freerdp.

## Limitations / Known Issues

  * Sound not working, yet
  * Usernames containig blanks are not supported.
