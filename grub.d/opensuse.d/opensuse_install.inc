echo iso_path $iso_path
echo title $title
echo boot_dir $boot_dir
echo medium $medium
echo imgdevpath $imgdevpath
echo prefix $prefix

read

menuentry "openSUSE Install via Memdisk" {
  bootoptions="ramdisk_size=512000 ramdisk_blocksize=4096 initrd=initrd splash=silent install=hd:$iso_path quiet showopts"
  linux /boot/bin/memdisk iso raw
  initrd $iso_path
}


menuentry "openSUSE Install" {
  bootoptions="isoloop=$iso_path ramdisk_size=512000 ramdisk_blocksize=4096 initrd=initrd splash=silent install=hd:$iso_path quiet showopts"
  linux (loop)/boot/$boot_dir/loader/linux $bootoptions
  initrd (loop)/boot/$boot_dir/loader/initrd
}

menuentry "Failsafe --- openSUSE Install    " {
  bootoptions="isofrom_device=$imgdevpath isofrom_system=$iso_path ramdisk_size=512000 ramdisk_blocksize=4096 splash=silent quiet showopts ide=nodma apm=off noresume edd=off powersaved=off nohz=off highres=off processsor.max+cstate=1 nomodeset x11failsafe"
  linux (loop)/boot/$boot_dir/loader/linux $bootoptions
  initrd (loop)/boot/$boot_dir/loader/initrd
}
