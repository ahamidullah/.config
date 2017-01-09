#!/bin/sh

ad() {
	cd "$1" && awd $sysname;
}

g() {
	grep -n "$@" *.* /dev/null
}

cw() {
	w() {
		9p write acme/$winid/$1
	}

	r() {
		9p read acme/$winid/$1
	}

	ctl() {
		$PLAN9/bin/echo -n "$@" | w ctl
	}

	$PLAN9/bin/echo -n Edit ,d | w body
	$PLAN9/bin/echo -n /Edit ,d/ | w addr
	ctl dot=addr
	r addr | awk '{printf("MX%s %s\n", $1, $2)}' | w event
}

