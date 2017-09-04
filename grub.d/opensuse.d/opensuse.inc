if [ "${type}" = "live" ]; then
  menuentry "Boot openSUSE Live medium" {
    bootoptions="isofrom_device=$imgdevpath isofrom_system=$iso_path ramdisk_size=512000 ramdisk_blocksize=4096 splash=silent quiet showopts"
    linux (loop)/boot/$boot_dir/loader/linux $bootoptions
    initrd (loop)/boot/$boot_dir/loader/initrd
  }
  menuentry "Failsafe --- Boot openSUSE Live medium" {
    bootoptions="isofrom_device=$imgdevpath isofrom_system=$iso_path ramdisk_size=512000 ramdisk_blocksize=4096 splash=silent quiet showopts ide=nodma apm=off noresume edd=off powersaved=off nohz=off highres=off processsor.max+cstate=1 nomodeset x11failsafe"
    linux (loop)/boot/$boot_dir/loader/linux $bootoptions
    initrd (loop)/boot/$boot_dir/loader/initrd
  }
fi
if [ "${type}" = "install" ]; then
  if [ "${version}-${medium}" = "Tumbleweed-DVD" ]; then
#    if [ "${version}" = "Tumbleweed" ]; then
      if [ ! "${ext}" = "iso.d" ]; then
        echo "Warning: OpenSUSE Tumbleweed Installation from ISO files may fail because of repository mounting errors"
        echo "To work around this issue, unpack ISO file into a directory and give it the ending '.iso.d'"
        echo "Press enter to proceed"
        read 
      fi
#    fi
  fi
  menuentry "openSUSE Installation" {
    bootoptions="ramdisk_size=512000 ramdisk_blocksize=4096 initrd=initrd splash=silent $install_option quiet showopts"
    linux $kernel_path_prefix/boot/$boot_dir/loader/linux $bootoptions
    initrd $kernel_path_prefix/boot/$boot_dir/loader/initrd
  }

  menuentry "openSUSE Rescue System" {
    bootoptions="ramdisk_size=512000 ramdisk_blocksize=4096 initrd=initrd splash=silent $install_option quiet showopts rescue=1"
    linux $kernel_path_prefix/boot/$boot_dir/loader/linux $bootoptions
    initrd $kernel_path_prefix/boot/$boot_dir/loader/initrd
  }


  menuentry "Failsafe --- openSUSE Installation" {
    bootoptions="ramdisk_size=512000 ramdisk_blocksize=4096 splash=silent quiet showopts ide=nodma apm=off noresume edd=off powersaved=off nohz=off highres=off processsor.max+cstate=1 nomodeset x11failsafe $install_option"
    linux $kernel_path_prefix/boot/$boot_dir/loader/linux $bootoptions
    initrd $kernel_path_prefix/boot/$boot_dir/loader/initrd
  }
fi

