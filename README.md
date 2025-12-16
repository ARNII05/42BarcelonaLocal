# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Readme.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellavi <abellavi@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 10:47:33 by abellavi          #+#    #+#              #
#    Updated: 2025/12/11 10:48:30 by abellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SPANISH VERSION:

𝔈𝔰𝔱𝔢 𝔭𝔯𝔬𝔶𝔢𝔠𝔱𝔬 𝔥𝔞 𝔰𝔦𝔡𝔬 𝔠𝔯𝔢𝔞𝔡𝔬 𝔠𝔬𝔪𝔬 𝔭𝔞𝔯𝔱𝔢 𝔡𝔢𝔩 𝔠𝔲𝔯𝔯𝔦𝔠𝔲𝔩𝔬 𝔡𝔢 42 𝔭𝔬𝔯 𝔞𝔟𝔢𝔩𝔩𝔞𝔳𝔦

**DESCRIPCION**

Este proyecto se llama Born2beRoot.

Trata de configurar una maquina virtual usando VirtualBox.

Estos son los requisitos que piden:

1. Crear 2 particiones encriptadas usando LVM.
2. Que ssh tiene que funcionar en el puerto 4242. Root no puede usar ssh.
3. Se debe configurar UFW (en caso de Debian) y dejar solo el puerto 4242 abierto.
4. El hostname debe ser nombreusuario42(en mi caso es abellavi42).
5. Implementar una politica de contraseñas fuerte.
6. Configurar sudo como piden.
7. Configurar un script para que ejecute una serie de comandos. 
8. A parte de un usuario root, tiene que haber un usuario con tu login normal.
9. El usuario con tu login tiene que pertenecer a 2 grupos: user42 y sudo.

Se pueden usar estos sistemas operativos:

1. Debian (es el que yo he usado porque he hecho poco de sistemas).
2. Rocky.

**INSTRUCCIONES**

1. Mirar si AppArmor y UFW (firewall) esta funcionando al iniciar la maquina.
2. Saber la diferencia entre (aptitude y apt) y (SELinux y AppArmor).
3. Se tiene que probar ssh con una nueva cuenta.
4. Crear un nuevo usuario y asignarlo a un grupo.
5. Saber como funciona el script.

**RECURSOS**

1. He usado ChatGPT para saber como implementar del punto 5-7.

**DESCRIPCION DEL PROYECTO**

**1. Decision del sistema operativo**

He usado Debian porque vi que el enunciado ponia que era muy recomendable usarlo si no tenias mucha experiencia en sistemas.

**2. Pros y contras de cada sistema operativo**

**Pros Debian**

1. Estable para servidores si no quieres problemas.
2. Muchos paquetes y versiones disponibles funcionales.
3. Puedes instalar las cosas a tu disposicion.
4. Mucha documetacion.
 
**Contras Debian**
1. Algunos paquetes no estan en sus versiones mas recientes.
2. Algunas configuraciones pueden ser avanzadas.
3. No tiene soporte comercial.

**Pros Rocky**

1. Fiable para produccion.
2. Nivel de seguridad bueno si sabes usarlo.
3. Actualizaciones mas estables que Debian.

**Contras Rocky**

1. SELinux puede ser complicado de configurar.
2. Menos paquetes que Debian.
3. No tiene tanta documentacion como Debian.

**3. Decisiones principales de**

**Particiones**

1. Hice la maquina virtual entera y cuando estaba dentro ya hice las particiones, se me hizo mas facil de esta manera.

2. He usado comandos como: fdisk, cryptsetup, mkdir, mkfs y mount.

**Politica de seguiridad**

1. He editado algunos archivos para poder implementar las reglas de contraseñas fuerte 
	1. /etc/pam.d/sudo
	2. /etc/security/pwquality.conf
2. Para el script tambien es un archivo: /usr/local/bin/monitoring.sh
3. Registrar el input de sudo: /var/log/sudo
4. Modo TTY: /etc/sudoers
5. Para editar sudoers: sudo visudo

**Manejo de usuarios**

1. He usado los comandos para crear usuarios que pide el enunciado y ponerle a los grupos correspondientes

Servicios instalados:

Cryptsetup,libpam-pwquality (para reglas de contraseñas), ssh, sudo.

**4. Comparaciones entre**

**Debian vs Rocky Linux**

1. Base

* Debian: Independiente, estable, comunidad fuerte
* Rocky: Fork de RHEL, compatible con Red Hat Enterprise Linux

2. Estabilidad

* Debian: Muy alta (ideal servidores)
* Rocky: Alta, orientada a producción empresarial

3. Actualizaciones

* Debian: Más conservadoras (paquetes antiguos pero muy probados)
* Rocky: Más recientes que Debian estable, especialmente para software empresarial

4. Seguridad 

* Debian: AppArmor, actualizaciones regulares
* Rocky: SELinux activo por defecto, más control granular

**AppArmor vs SELinux**

1. Modelo

* AppArmor: Basado en perfiles de aplicación
* SELinux: Basado en políticas de acceso obligatorio (Mandatory Access Control)

2. Curva de aprendizaje

* AppArmor: Más sencillo, perfiles fáciles de modificar
* SELinux: Más complejo, requiere entender políticas y contextos

3. Seguridad

* AppArmor: Buena, protege aplicaciones específicas
* SELinux: Muy fuerte, protege todo el sistema con reglas granulares

4. Fexibilidad

* AppArmor: Menos granular, menos intrusivo
* SELinux: Muy granular, puede ser restrictivo si se configura mal

**UFW vs Firewalld**

1. Objetivo 

* UFW: Configuración sencilla de firewall.
* Firewalld: Configuración avanzada de firewall con zonas y servicios

2. Facilidad

* UFW: Muy fácil, comandos simples.
* Firewalld: Moderada, requiere aprender zonas y servicios

3. Integracion

* UFW: Ubuntu/Debian-friendly.
* Firewalld: CentOS/RHEL/Rocky-friendly

4. Uso recomendado

* UFW: Pequeños servidores, escritorio.
* Firewalld: Servidores empresariales, entornos con múltiples zonas de red

**VirtualBox vs UTM**

1. Plataformas

* VirtualBox: Multiplataforma.
* UTM: Principalmente macOS.

2. Facilidad de uso

* VirtualBox: Facil de instalar y usar.
* UTM: En macOS relativamente fácil, menos documentación en Linux.

3. Rendimiento

* VirtualBox: Depende de host.
* UTM: Menor rendimiento en algunos casos porque usa QEMU.

4. Funciones

* VirtualBox: Snapshots, soporte de múltiples OS, networking avanzado.
* UTM: Menor rendimiento en algunos casos porque usa QEMU.


ENGLISG VERSION

𝔗𝔥𝔦𝔰 𝔭𝔯𝔬𝔧𝔢𝔠𝔱 𝔥𝔞𝔰 𝔟𝔢𝔢𝔫 𝔠𝔯𝔢𝔞𝔱𝔢𝔡 𝔞𝔰 𝔭𝔞𝔯𝔱 𝔬𝔣 𝔱𝔥𝔢 42 𝔠𝔲𝔯𝔯𝔦𝔠𝔲𝔩𝔲𝔪 𝔟𝔶 𝔞𝔟𝔢𝔩𝔩𝔞𝔳𝔦

**DESCRIPTION**

This project is called Born2beRoot.

It is about configuring a virtual machine using VirtualBox.

These are the requirements:

1. Create 2 encrypted partitions using LVM.
2. SSH must work on port 4242. Root cannot use SSH.
3. UFW must be configured (if using Debian) and only port 4242 should be open.
4. The hostname must be yourusername42 (in my case, it is abellavi42).
5. Implement a strong password policy.
6. Configure sudo as requested.
7. Configure a script to execute a series of commands.
8. Besides the root user, there must be a user with your normal login.
9. The user with your login must belong to 2 groups: user42 and sudo.

These operating systems can be used:

1. Debian (this is the one I used because I have little experience with systems).
2. Rocky.

**INSTRUCTIONS:**

1. Check if AppArmor and UFW (firewall) are running when the machine starts.
2. Know the difference between (aptitude and apt) and (SELinux and AppArmor).
3. SSH must be tested with a new account.
4. Create a new user and assign it to a group.
5. Understand how the script works.

**RESOURCES:**

1. I used ChatGPT to know how to implement points 5–7.

**PROJECT DESCRIPTION:**

1. **Operating System Decision**

I used Debian because I saw that the instructions recommended it if you didn’t have much experience with systems.

2. **Pros and Cons of Each Operating System**

**Debian Pros:**

1. Stable for servers if you don’t want problems.
2. Many functional packages and versions available.
3. You can install things at your disposal.
4. Plenty of documentation.

**Debian Cons:**

1. Some packages are not the latest versions.
2. Some configurations can be advanced.
3. No commercial support.

**Rocky Pros:**

1. Reliable for production.
2. Good security level if you know how to use it.
3. More stable updates than Debian.

**Rocky Cons:**

1. SELinux can be complicated to configure.

2. Fewer packages than Debian.

3. Less documentation than Debian.

4. **Main Decisions**

**Partitions:**

1. I created the entire virtual machine first, and once inside, I made the partitions. This was easier for me.
2. I used commands such as: fdisk, cryptsetup, mkdir, mkfs, and mount.

**Security Policy:**

1. I edited some files to implement strong password rules:

   * /etc/pam.d/sudo
   * /etc/security/pwquality.conf
2. For the script, there is also a file: /usr/local/bin/monitoring.sh
3. Log sudo input: /var/log/sudo
4. TTY mode: /etc/sudoers
5. To edit sudoers: sudo visudo

**User Management:**

1. I used the commands to create users as requested and assign them to the corresponding groups.

**Installed Services:**

Cryptsetup, libpam-pwquality (for password rules), SSH, sudo.

**4. Comparisons**

**Debian vs. Rocky Linux**

1. Base

* Debian: Independent, stable, strong community
* Rocky: RHEL fork, compatible with Red Hat Enterprise Linux

2. Stability

* Debian: Very high (ideal for servers)
* Rocky: High, aimed at enterprise production

3. Updates

* Debian: More conservative (older but well-tested packages)
* Rocky: More recent than stable Debian, especially for enterprise software

4. Security

* Debian: AppArmor, regular updates
* Rocky: SELinux active by default, more granular control

**AppArmor vs. SELinux**

1. Model

* AppArmor: Based on application profiles
* SELinux: Based on Mandatory Access Control policies

2. Learning Curve

* AppArmor: Simpler, easy-to-modify profiles
* SELinux: More complex, requires understanding policies and contexts

3. Security

* AppArmor: Good, protects specific applications
* SELinux: Very strong, protects the entire system with granular rules

4. Flexibility

* AppArmor: Less granular, less intrusive
* SELinux: Very granular, can be restrictive if misconfigured

**UFW vs. Firewalld**

1. Purpose

* UFW: Simple firewall configuration
* Firewalld: Advanced firewall configuration with zones and services

2. Ease of Use

* UFW: Very easy, simple commands
* Firewalld: Moderate, requires learning zones and services

3. Integration

* UFW: Ubuntu/Debian-friendly
* Firewalld: CentOS/RHEL/Rocky-friendly

4. Recommended Use

* UFW: Small servers, desktops
* Firewalld: Enterprise servers, environments with multiple network zones

**VirtualBox vs. UTM**

1. Platforms

* VirtualBox: Cross-platform
* UTM: Mainly macOS

2. Ease of Use

* VirtualBox: Easy to install and use
* UTM: Relatively easy on macOS, less documentation on Linux

3. Performance

* VirtualBox: Depends on the host
* UTM: Lower performance in some cases because it uses QEMU

4. Features

* VirtualBox: Snapshots, multiple OS support, advanced networking
* UTM: Lower performance in some cases because it uses QEMU

