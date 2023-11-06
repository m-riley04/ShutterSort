The files in this folder are for if any updates to the container need to be made.

DO NOT LAUNCH YOUR CONTAINER IN THIS FILE ONLY USE THE FILES ON YOUR LOCAL COMPUTER.
main reason for this is when you launch a container it makes files inside your vagrant folder
that is special to yours. keeping it seprate keeps your git pushes more clean.

When there is an update most likely it is just the Dockerfile unless told otherwise.
Step 1. Go to the Vagrant folder that is local to you and open it. open the file that will be updated

Step 2. Open the Vagrant_Files folder in the repo

Step 3. Best way would to just copy the entire updated file in the Vagrant_Files and paste into
the file that is being updated. make sure its the entire file

Step 4. make sure to save the file and you can close the repo if wanted

Step 5. open a terminal at your local Vagrant folder where when you use ls it should look like
"""
(base) rylandedwards@Rylands-MacBook-Pro Vagrant % ls
Dockerfile	Vagrantfile	compose.yaml
"""

Step 6. type the command "vagrant reload" and pray it works