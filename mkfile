<mkconfig
MKSHELL = rc

all :Q:

% :QV:
	for(d in $DIRS){
		echo '(cd '$d'; mk '$target')'
		{ builtin cd $d ; mk $MKFLAGS $stem; cd .. }
	}

$DIRS :QV:
	echo '(cd '$target'; mk '$target')'
	cd $target
	mk $MKFLAGS $target
	cd ..
