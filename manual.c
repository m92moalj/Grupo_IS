/*Guia de GIT
23-10-14
Ingenieria del Software

*/

//DESCARGAR EL REPOSITORIO
m92moalj@RYCS3027:~$ git clone https://github.com/m92moalj/practicas-is.git
Cloning into 'practicas-is'...
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 0 (delta 0)
Unpacking objects: 100% (4/4), done.
m92moalj@RYCS3027:~$ 

//CD DIRECTORIO
m92moalj@RYCS3027:~$ ls
2a.c  BD  Descargas  Desktop  examen.c	IP  MP	practicas-is
m92moalj@RYCS3027:~$ cd practicas-is/
m92moalj@RYCS3027:~/practicas-is$ ls
LICENSE  README.md
m92moalj@RYCS3027:~/practicas-is$ 

//GIT STATUS
m92moalj@RYCS3027:~/practicas-is$ git status
# On branch master
nothing to commit, working directory clean
m92moalj@RYCS3027:~/practicas-is$  

//GIT COMMIT
m92moalj@RYCS3027:~/practicas-is$ git commit
# On branch master
nothing to commit, working directory clean
m92moalj@RYCS3027:~/practicas-is$ 

//MODIFICAR EL README.MD
m92moalj@RYCS3027:~/practicas-is$ gedit README.md &
[1] 5218
m92moalj@RYCS3027:~/practicas-is$ git status
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#	modified:   README.md
#
no changes added to commit (use "git add" and/or "git commit -a")
[1]+  Hecho                   gedit README.md
m92moalj@RYCS3027:~/practicas-is$ git diff
diff --git a/README.md b/README.md
index 0fe4c74..90b2ab0 100644
--- a/README.md
+++ b/README.md
@@ -2,3 +2,8 @@ practicas-is
 ============
 
 Práctica de ingeniera del software
+
+#Introduccion
+Esta es la primera practica de IS
+##Fecha
+23-10-14
m92moalj@RYCS3027:~/practicas-is$ 


//AÑADIMOS EL README
m92moalj@RYCS3027:~/practicas-is$ git add README.md 

//HACEMOS COMMIT
m92moalj@RYCS3027:~/practicas-is$ git commit README.md -m "DOCUMENTAMOS FICHERO"
[master 78975d5] COMENTARIO
 1 file changed, 5 insertions(+)
m92moalj@RYCS3027:~/practicas-is$ git status
# On branch master
# Your branch is ahead of 'origin/master' by 1 commit.
#   (use "git push" to publish your local commits)
#
nothing to commit, working directory clean

//CONSULTAMOS LAS RAMAS QUE HAY
m92moalj@RYCS3027:~/practicas-is$ git branch
* master

//MODIFICACIONES

m92moalj@RYCS3027:~/practicas-is$ git log                                      
commit 78975d51ceeecd97aa6a4a67c13975da6c9f4d2a
Author: Jorge Molina Alba <molina3017.jm@gmail.com>
Date:   Thu Oct 23 13:52:40 2014 +0200

    "DOCUMENTAMOS FICHERO"

commit 8fd826e35c6310289829518c544309c354a6b62a
Author: m92moalj <molina3017.jm@gmail.com>
Date:   Thu Oct 23 13:34:20 2014 +0200

    Initial commit


//CREAR Y BORRAR RAMAS

git branch testing
git branch
* master
  testing

git branch -d testing
Deleted branch testing (was 78975d5).
git branch
* master

//CAMBIAR DE RAMA PRINCIPAL

m92moalj@RYCS3027:~/practicas-is$ git checkout testing
Switched to branch 'testing'
m92moalj@RYCS3027:~/practicas-is$ git branch
  master
* testing

//CREAR ARCHIVO VACIO
m92moalj@RYCS3027:~/practicas-is$ touch ejemplo.c

//ls
ejemplo.c  LICENSE  README.md

//COMMIT Y FUSIONAR
m92moalj@RYCS3027:~/practicas-is$ git commit ejemplo.c -m "Primera version"
error: pathspec 'ejemplo.c' did not match any file(s) known to git.
m92moalj@RYCS3027:~/practicas-is$ git checkout master
Switched to branch 'master'
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)
m92moalj@RYCS3027:~/practicas-is$ git branch
* master
  testing
m92moalj@RYCS3027:~/practicas-is$ git merge testing
Already up-to-date.
m92moalj@RYCS3027:~/practicas-is$ ls
ejemplo.c  LICENSE  README.md

//SUBIR A LA WEB
m92moalj@RYCS3027:~/practicas-is$ git push
warning: push.default is unset; its implicit value is changing in
Git 2.0 from 'matching' to 'simple'. To squelch this message
and maintain the current behavior after the default changes, use:

  git config --global push.default matching

To squelch this message and adopt the new behavior now, use:

  git config --global push.default simple

See 'git help config' and search for 'push.default' for further information.
(the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
'current' instead of 'simple' if you sometimes use older versions of Git)

Username for 'https://github.com': m92moalj
Password for 'https://m92moalj@github.com': 
Counting objects: 5, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 395 bytes | 0 bytes/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To https://github.com/m92moalj/practicas-is.git
   8fd826e..78975d5  master -> master


//AÑADIR LA OTRA RAMA

m92moalj@RYCS3027:~/practicas-is$ git push origin testing
Username for 'https://github.com': m92moalj
Password for 'https://m92moalj@github.com': 
Total 0 (delta 0), reused 0 (delta 0)
To https://github.com/m92moalj/practicas-is.git
 * [new branch]      testing -> testing



//VER TODAS LAS RAMAS Y ENTRAR A UNA DISTINTA A LA MASTER
i32ropie@i32ropie~/Grupo_IS $ git branch -a //Vemos todas las ramas
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/POO_P2
  remotes/origin/auxiliar
  remotes/origin/master

i32ropie@i32ropie~/Grupo_IS $ git checkout POO_P2 //Nos descargamos POO_P2 (por ejemplo)
Branch POO_P2 set up to track remote branch POO_P2 from origin.
Switched to a new branch 'POO_P2'

i32ropie@i32ropie~/Grupo_IS $ ls //Vemos contenido y comprobamos que nos cambiamos bien de rama.
holamundo.c  LICENSE  manual.c  POO_P2.tar.gz  R001.txt  R002.txt  R003.txt  README.md  requisitos.txt

i32ropie@i32ropie~/Grupo_IS $ git checkout master //Volvemos a master.
Switched to branch 'master'

i32ropie@i32ropie~/Grupo_IS $ ls //Y vemos que el contenido de ahora es el de master.
Desktop.rar  Documentacion/  holamundo.c  LICENSE  manual.c  R001.txt  R002.txt  R003.txt  README.md  requisitos.txt  SO
