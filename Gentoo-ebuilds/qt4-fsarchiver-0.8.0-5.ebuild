# Copyright 1999-2014 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: Necrose99 Proxymaintier  Exp $
#ssh-fs & cifs / samba are highly recomened for network backups and LIVE rescue type disk/s
EAPI=6

inherit qmake-utils versionator

MY_P="${PN}-$(replace_version_separator 3 '-')"
MIN_PV="$(get_version_component_range 1-3)"

DESCRIPTION="Qt4 frontend for fsarchiver"
HOMEPAGE="http://qt4-fsarchiver.sourceforge.net/"
## live ebuilds of 9999 may fail. also note all translations may not be avlible if live DieterBaum still has to code them in.

if [[ ${PV} = 9999* ]]; then
	EGIT_REPO_URI="https://github.com/DieterBaum/qt4-fsarchiver.git"
	inherit git-2
else
	SRC_URI="https://github.com/DieterBaum/qt4-fsarchiver/releasesv${PV}.tar.gz
	mirror://sourceforge/${PN}/source/${MY_P}.tar.gz"
	KEYWORDS="amd64 arm hppa ~mips ppc ppc64 x86"
fi

LICENSE="GPL-2"
SLOT="0"

IUSE=""

CDEPEND="app-arch/bzip2
	app-arch/xz-utils
	dev-libs/libgcrypt:=
	dev-libs/lzo
	dev-qt/qtcore:4
	dev-qt/qtgui:4
	sys-apps/util-linux
	sys-fs/e2fsprogs
	sys-libs/zlib"
RDEPEND="${CDEPEND}
	>=app-backup/fsarchiver-${MIN_PV}[lzma,lzo]"
DEPEND="${CDEPEND}"

S="${WORKDIR}/${PN}"

src_prepare() {
	# fix .desktop file
	sed -i \
		-e '/Encoding/d' starter/"*${PN}"*.desktop \
		|| die "sed on qt4-fsarchiver.desktop failed"
	# fix icon installation location
	sed -i \
		-e "/icon.path/s:app-install/icons:${PN}:" "*${PN}"*.desktop \
		|| die "sed on ${PN}.pro failed"
}
src_configure() {
	eqmake
}
src_install() {
	emake INSTALL_ROOT="${D}" install
	einstalldocs
}

pkg_postinst() {
	elog "optional dependencies:"
	elog "  sys-fs/btrfs-progs"
	elog "  sys-fs/jfsutils"
	elog "  sys-fs/ntfs3g[ntfsprogs]"
	elog "  sys-fs/reiser4progs"
	elog "  sys-fs/reiserfsprogs"
	elog "  net-fs/sshfs"
	elog "  sys-fs/xfsprogs"
}
