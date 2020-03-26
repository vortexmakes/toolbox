# Git Memo (yet another cheat sheet)
## Contents

- [References and tools](#references-and-tools)
	- [Learning Git](#learning-git)
	- [Visual cheat sheet](#visual-cheat-sheet)
	- [Book](#book)
- [Setup](#setup)
	- [File ending](#file-ending)
	- [Using Vim](#using-vim)
	- [How to remove crtl-M](#how-to-remove-ctrl-m)
- [Colors in GIT](#colors-in-git)
- [Exclude](#exclude)
- [Add](#add)
- [Help](#help)
- [Revert](#revert)
	- [Commit](#commit)
		- [Add file to last commit](#add-file-to-last-commit)
	- [File](#file)
		- [Changing file to old commit](#changing-file-to-old-commit)
		- [Recovery deleted file](#recovery-deleted-file)
- [Diff](#diff)
- [Remove files](#remove-files)
- [Moving files](#moving-files)
- [History](#history)
- [Init](#init)
- [Cloning](#cloning)
- [Branches](#branches)
	- [Listing](#listing)
	- [Remote branches](#remote-branches)
- [Tag](#tag)
- [List files](#list-files)
- [Alias](#alias)
- [Pull & Push](#pull--push)
- [Merge](#merge)
- [Stash](#stash)
- [Submodule](#submodule)
	- [Update submodule](#update-submodule)
	- [Tie to specific branch](#tie-to-specific-branch)
	- [Tie to specific tag](#tie-to-specific-tag)
- [Archive](#archive)
- [Migrating svn to git](#migrating-svn-to-git)
- [Support for Subversion clients](#support-for-subversion-clients)
- [Duplicating a repository](#duplicating-a-repository)
- [Git LFS](#git-lfs)

------------------------------------------------------------------------------
## References and tools
### Learning Git
https://learngitbranching.js.org/
https://www.katacoda.com/courses/git 
### Visual cheat sheet
http://www.ndpsoftware.com/git-cheatsheet.html#loc=local_repo;
### Book
https://git-scm.com/book/es/v1

## Setup
```bash
git config global --unset credential.helper # unforget the user/password
git config --global -l # list options. Could be used <--system> or <--local>
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
git config --global core.editor vim
git config --global merge.tool vimdiff
cat ~/.gitconfig # Verify global options
```
https://git-scm.com/book/es/v1/Empezando-Configurando-Git-por-primera-vez

## File ending
```bash
git config core.autocrlf # File format: unix = LF and dos = CRLF
git config --global core.autocrlf input # recommended config
```
http://stackoverflow.com/questions/1967370/git-replacing-lf-with-crlf/20653073#20653073
### Using Vim
http://vim.wikia.com/wiki/File_format

### How to remove ctrl-M
Find no utf-8 characters
```bash 
grep -P "[\x80-\xFF]" <file>
```
Using the stream editor sed:
```bash
sed -e "s/\r//g" file > newfile
```
Using vim
```bash
:%s/^M//g
```

## Colors in GIT
```bash
$ git --config color.ui [true | false] # Terminal colors output
```

## Exclude
```bash
$ cat .git/info/exclude # specifies intentionally untracked files 
                        # that Git should ignore (local)
$ cat .gitignore # local
# Copy ignore file from .git/info/exclude or .gitignore or other 
# (Github ...)
$ cp .git/info/exclude ~/.config/git/ignore # global
$ git config --global core.excludesFile ~/.config/git/ignore
```
## Add
```bash
$ git add -A # stages All
$ git add . # stages new and modified, without deleted
$ git add -u # stages modified and deleted, without new
```
## Help
```bash 
$ git help <command>
$ git <command> --help
$ man git-<command>
```
## Revert
### Commit
```bash
$ git commit --amend # modify last commit with the current index changes
$ git reset --soft HEAD^ # undo last commit, without changing working dir or stage
```
#### Add file to last commit
```bash
$ git add the_left_out_file
$ git commit --amend --no-edit
```
### File
```bash
$ git checkout <file> # unmodify a modified file from working directory
$ git reset # (--mixed) back to where it was, without changing working dir
$ git reset --hard # back to where it was, changing working and stage
$ git reset <file> # unstaging a Staged File
$ git reset [commit] <file> # update <file> to <commit> in stage area
``````
#### Changing file to old commit
```bash
$ git reset <old_commit> <file>
$ git status
$ git diff --staged <file> # show diffs between index and commit
$ git diff <file> # show diffs between index and working dir
$ git checkout -- <file>
```
#### Recovery deleted file
```bash
$ git reset HEAD <file> 
$ git checkout -- <file> 
```
https://git-scm.com/book/en/v2/Git-Tools-Reset-Demystified
*reset: moves the branch that HEAD points to*
*checkout: moves the HEAD to point to other branch*

## Diff
```bash
$ git diff # Changes in the working tree not yet staged 
           # for the next commit

# Changes between your last commit and the index; what you would be committing if you run "git commit" without "-a" option
$ git diff --staged
$ git diff --cached HEAD
	
# Changed files between your last commit and the index
$ git diff-index --cached HEAD

# Compare the version before the last commit and the last commit
$ git diff HEAD^ HEAD

# Difference for a file "main.c" between now and two commits back
$ git diff HEAD^^ HEAD main.c
$ git diff HEAD~2 HEAD main.c
```

## Remove files
```bash
$ git rm --cached <file> # remove from stage  area
$ git rm -f <file> # remove from working directory and stages area
$ rm <file> # remove untracked file
```

## Moving files
```bash
$ git mv <old_file> <new_file> # rename <old_file>
```

## History
```bash
$ git log
$ git log -p -2 # with diff and the last 2 commits
$ git log --stat # with statistics (files, changes, ...)
$ git log --after="2016-8-1" --before="2016-12-31" # between dates
$ git log --since=2.weeks # from date
$ git log --pretty=format:"%h - %an, %ad : %s" # with customizable format
$ git log --pretty=format:"%h %s" --graph # with ASCII graph
$ git log --pretty=oneline # overview
$ git log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all

$ git log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''%C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all
```

https://git-scm.com/book/es/v1/Fundamentos-de-Git-Viendo-el-hist%C3%B3rico-de-confirmaciones

## Init
```bash
# Create an empty Git repository or reinitialize an existing one
cd path
git init 
git remote add origin <url>
git add <files>
git commit 
git push -u origin master
```

## Cloning
```bash
# Clones a repository into a newly created directory, 
# creates remote-tracking branches for each branch in the 
# cloned repository (visible using git branch -r), 
# and creates and checks out an initial branch that is forked 
# from the cloned 
# repository's currently active branch. */
$ git clone <remote> [-b <branch>] [<directory>]
```

## Branches
```bash
$ git checkout <branch> # switch to <branch>
$ git checkout -b '<branch>' # creates <branch> and switch to it
$ git branch -d <branch> # delete <branch>
```

### Listing
```bash
$ git remote [-v] # shows remote repositories [with url]
$ git branch # existing branches are listed
$ git branch -vv # list remote-tracking branches to be listed
$ git branch -a # list all branches (local + remote)
$ git branch -v # list branches and its pointers (commit)
$ git branch --merged # list merged branches
```

### Remote branches
```bash
# Create the branch <remote_branch> in the <remote> by copying the 
# current <local_branch> and track it by adding the up-stream reference
$ git push -u <remote> <local_branch>:<remote_branch>

# Find a ref that matches <local_branch> in the source repository 
# and update the same ref in <remote> repository with it, also it's 
# tracked with -u. If <local_branch> did not exist remotely, it would 
# be created
$ git push -u origin <local_branch>

# Defines the action "git push" should take if no refspec is given on the # command line, no refspec is configured in the remote, and no refspec is # implied by any of the options given on the command line. In this case: # upstream - push the current branch to its upstream branch
git config [--local | --global | --system] push.default upstream
	
# Delete remote_branch from remote
$ git push <remote> :<remote_branch>
	
# Set default up-stream for current branch on use git pull/merge. 
# See ~/.git/config
$ git branch -u <remote>/<remote_branch> <local_branch>

# Gives some information about the remote <repo>
$ git remote show <repo>

# Add local_branch tracking the remote_branch in <remote> and switch 
# to it
$ git remote -r # verify remotes
$ git fetch origin # update local repository from origin
$ git branch -avv # verify branches
$ git checkout -b <local_branch> [--track] <remote>/<remote_branch>
	
$ git remote -r # verify remotes
$ git clone <remote> -b <remote_branch> <directory>
$ git branch -avv # verify branches
$ git checkout -b <local_branch> <remote>/<remote_branch>
```

## Tag
```bash
$ git tag # show
$ git tag -a v1.2 -m 'version 1.2' 9fceb02  # creating for a commit
$ git tag -a v1.0 -m 'version 1.0' # creating for HEAD
$ git push origin <tagname> # sharing
$ git push origin --tags # sharing all
```

## List files
```bash
$ git ls-files
```

## Alias
```bash
# in ~/.gitconfig
[alias]
lg1 = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all
lg2 = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''              %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all
lg = !"git lg1"
```

## Pull & Push
```bash
# Fetch from and integrate with another repository into the 
# current branch
$ git pull <remote>
# shorthand:
$ git fetch <remote>
$ git merge FETCH_HEAD
# If you tried a pull which resulted in complex conflicts and 
# would want to start over, you can recover with 
# git reset --hard ORIG_HEAD

$ git push <remote> <branch>
$ git diff <commit> <commit> # diff between commits

#### Show changes to be pushed
# For a list of files to be pushed
git diff --stat --cached [remote/branch] # Example [origin/master]
	
# For the code diff of the files to be pushed
git diff [remote repo/branch file_path]

# To see full file paths of the files that will change
git diff --numstat [remote repo/branch]
```

## Merge
```bash
$ git config merge.tool vimdiff # get it before set it
$ git config merge.conflictstyle diff3 # get it before set it
$ git checkout <branch_to_update> # switch to current branch
$ git merge <branch> # merge changes from <branch> into current
$ git mergetool # if there are conflicts
:diffget RE # in vimdiff to get from remote or local (LO) or base (BA)
$ git merge --abort
$ git merge --no-ff <branch> # causes the merge to always create a 
                            # new commit object
```
https://gist.github.com/karenyyng/f19ff75c60f18b4b8149

## Stash
```bash
# stashing code with git stash
# ... hack hack hack ...
$ git stash 
$ edit emergency fix could be create a temp branch
$ git commit -a -m "Fix in a hurry" 
$ git stash pop 
# ... continue hacking ...
# stashing code without git stash
# ... hack hack hack ...
$ git checkout -b my_wip 
$ git commit -a -m "WIP" 
$ git checkout master 
$ edit emergency fix 
$ git commit -a -m "Fix in a hurry" 
$ git checkout my_wip 
$ git reset --soft HEAD^ 
# ... continue hacking ...
```

## Submodule
```bash
$ cd third-party
$ git submodule add https://github.com/ThrowTheSwitch/Ceedling.git ceedling # ignored for clone process
$ git submodule init
$ git submodule update
$ cd ceedling
$ git submodule init
$ git submodule update
# Or
$ git clone --recurse-submodules <repo_url>
# Or
$ cd third-party
$ git submodule update --remote third-party/rkh
```

### Update submodule
```bash
$ git config -f .gitmodules submodule.<submodule>.branch <branch or commit>
$ git submodule update --remote <submodule_path>
```

### Tie to specific branch
```bash
git config -f .gitmodules submodule.<submodule>.branch <branch>
```

### Tie to specific tag
```bash
git config -f .gitmodules submodule.<submodule>.tag <tag>
```

## Archive
```bash
# Create an archive of files from a named tree
$ git archive --worktree-attributes -o <file>.zip origin/master # or master
```

## Migrating svn to git
```bash
# Extracting authors from svn
mkdir ~/dynalogin-conversion
cd ~/dynalogin-conversion
svn checkout \
  https://dynalogin.svn.sourceforge.net/svnroot/dynalogin dynalogin-svn-full
cd dynalogin-svn-full
svn log -q | \
 awk -F '|' '/^r/ {sub("^ ", "", $2); sub(" $", "", $2); print $2" = "$2" "}' \
 | sort -u > ~/dynalogin-conversion/authors-transform.txt
cd ~/dynalogin-conversion/
vim authors-transform.txt
# Edit the authors file by hand
# After the = symbol on each line, put the full name and email address that should be used
# in the git log. For example: d_pocock = Daniel Pocock <daniel@pocock.com.au>

# Migrating
mkdir ~/dynalogin-conversion
cd ~/dynalogin-conversion
git svn clone \
 https://dynalogin.svn.sourceforge.net/svnroot/dynalogin \
 --no-metadata \
 -A ~/dynalogin-conversion/authors-transform.txt \
 --stdlayout \
 dynalogin-git-tmp

mkdir ~/dynalogin-conversion/dynalogin.git
cd ~/dynalogin-conversion/dynalogin.git/
git init --bare .
git symbolic-ref HEAD refs/heads/trunk

cd ~/dynalogin-conversion/dynalogin-git-tmp
git remote add bare ~/dynalogin-conversion/dynalogin.git
git config remote.bare.push 'refs/remotes/*:refs/heads/*' 
#git config remote.bare.push 'refs/remotes/origin/*:refs/heads/*'
git push bare

cd ~/dynalogin-conversion/dynalogin.git/
git branch -m trunk master
git for-each-ref --format='%(refname)' refs/heads/tags | cut -d / -f 4 | while read ref; \
 do 
    git tag "$ref" "refs/heads/tags/$ref"
    git branch -D "tags/$ref"
 done
git remote add origin ssh://d_pocock@dynalogin.git.sourceforge.net/gitroot/dynalogin/dynalogin
git config branch.master.remote origin
git config branch.master.merge refs/heads/master
git push --tags origin master
	

https://danielpocock.com/migrating-a-sourceforge-project-from-subversion-to-git
$ git push --all
```

## Support for Subversion clients
From GitHub: https://help.github.com/en/articles/support-for-subversion-clients 

## Duplicating a repository
```bash
# If you want to mirror a repository in another location, including getting updates from the original, you can clone a mirror and periodically push the changes

# (1) Create a bare mirrored clone of the repository
git clone --mirror https://github.com/exampleuser/repository-to-mirror.git
	
# (2) Set the push location to your mirror
cd repository-to-mirror
git remote set-url --push origin https://github.com/exampleuser/mirrored

# (3) To update your mirror, fetch updates and push
git fetch -p origin
git push --mirror
```

## Git LFS
https://git-lfs.github.com/
https://help.github.com/en/articles/resolving-git-large-file-storage-upload-failures
https://medium.com/@AyunasCode/how-to-push-large-files-to-github-253d05cc6a09#.kfvv2fu5z
https://stackoverflow.com/questions/33360043/git-error-need-to-remove-large-file
https://help.github.com/en/articles/removing-sensitive-data-from-a-repository
