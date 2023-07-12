#!/bin/bash


echo "Sub Project of Devops"
echo "Project assigned by Jaswant Taur"
echo "project Date: wednesday july 12 , 2023"

#sender function 
sender() {
     read -p "Enter the file name :" file
     read -p "Enter the ip address:" ip
     read -p "Enter the username:" user
     systemctl start ssh.service    
     scp -r $file $user@$ip:~
}
# receiver fucntion 
receiver() {
        systemctl start ssh.service 
        systemctl status ssh.service 
}


select option in send receive help quit 
do 
        case $option in
                
                send)
                    sender
                    break
                    ;;
                receive)
                    receiver
                    break
                    ;;
                help)
                    echo "instruction of tool"
                    echo "when sharing file from different folder. provide the path of file. Example: /home/user/file.txt"
                    echo "use '  ip a  'for find right ip address example: en0"
                    echo "Enter the correct username.
                    "
                quit)
                    systemctl stop ssh.service
                    systemctl status ssh.service
                     break
                   ;;
                
                 *) echo "Invalid selection"
                   ;;
                   esac
done
