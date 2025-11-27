
# Das externe Modul für den ThemeBuilder laden
# (Annahme: ThemeBuilder.cmake liegt im Unterordner "cmake/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(ThemeBuilder)

# Liste der Icons definieren, die eingefärbt werden sollen (.svg.in)
# Diese müssen im Ordner "resources/icons/" liegen.
set(SIVAL_ICONS
    arrow-down.svg.in
    check.svg.in
    close.svg.in
    close_hover.svg.in
    cogwheel.svg.in
    enclosure.svg.in
    enclosure-fill.svg.in
    export.svg.in
    general.svg.in
    help.svg.in
    home.svg.in
    iconize.svg.in
    import.svg.in
    info.svg.in
    keyboard.svg.in
    max.svg.in
    min.svg.in
    minus.svg.in
    mouse.svg.in
    new.svg.in
    open.svg.in
    plus.svg.in
    print.svg.in
    projects.svg.in
    save.svg.in
    save_as.svg.in
)

# ==============================================================================
# 2. Theme Generierung (Aufrufe)
# ==============================================================================

# --- Generiere LIGHT Theme ---
create_theme(
    NAME "light"

    # Palette (Extrahiert aus Ihrer Vorlage)
    WINDOW_BG         "#E5E5E8"
    CONTENT_BG        "#FFFFFF"

    TEXT_PRIMARY      "#6B6B6E"
    TEXT_SECONDARY    "#ABABAE"
    TEXT_DISABLED     "#888888"

    BORDER_COLOR      "#C5C5C8"
    DIVIDER_COLOR     "#E5E5E8"

    HOVER_BG_CONTENT  "#F0F0F3"
    HOVER_BG_NAV      "#DADADD"
    HOVER_BG_ITEM     "#FCFCFF"

    SELECTION_BG      "#F5F5F8"

    SCROLL_TRACK      "#B5B5B8"
    SCROLL_HANDLE     "#A5A5A8"

    SECTION_BG        "#E0E0E3"
    SECTION_HOVER     "#D5D5D8"

    DESTRUCTIVE_COLOR "#FF0000"
    ACCENT_COLOR      "#0078D7"

    Icon-Konfiguration für Light (Dunkle Icons auf hellem Grund)
    ICONS      ${SIVAL_ICONS}
    ICON_COLOR "#6B6B6B"
)

# --- Generiere DARK Theme (SiVAL Standard) ---
create_theme(
    NAME "dark"

    # Palette (Angepasst an SiVAL Dark Logik: #1E1E1E / #2D2D30)
    WINDOW_BG         "#1E1E1E"  # Navigationsbereich (Dunkler)
    CONTENT_BG        "#2D2D30"  # Inhaltsbereich (Kühles Grau)

    TEXT_PRIMARY      "#CCCCCC"  # Helles Grau (nicht hartes Weiß)
    TEXT_SECONDARY    "#969696"
    TEXT_DISABLED     "#555555"

    BORDER_COLOR      "#3E3E3E"  # Subtile Grenzen
    DIVIDER_COLOR     "#1E1E1E"

    HOVER_BG_CONTENT  "#3E3E42"  # Hover im Inhalt
    HOVER_BG_NAV      "#252526"  # Hover in der Navigation
    HOVER_BG_ITEM     "#333333"

    SELECTION_BG      "#094771"  # Dunkles Blau für Selektionen

    SCROLL_TRACK      "#252526"
    SCROLL_HANDLE     "#424242"

    SECTION_BG        "#252526"
    SECTION_HOVER     "#2D2D30"

    DESTRUCTIVE_COLOR "#FF5555"  # Helleres Rot für Dark Mode
    ACCENT_COLOR      "#0078D7"  # Akzent bleibt gleich

    Icon-Konfiguration für Dark (Helle Icons)
    ICONS      ${SIVAL_ICONS}
    ICON_COLOR "#CCCCCC"
)


find_package(Qt6 REQUIRED COMPONENTS LinguistTools)


# Eine statische Bibliothek nur für die Ressourcen
add_library(sival-ressource SHARED
    light_theme.qrc
    dark_theme.qrc
    sival-settings.qrc
    settings/default_settings.sival
)

qt_add_translations(sival-ressource
    TS_FILES
        i18n/sival_de_DE.ts
        i18n/sival_en_EN.ts
    RESOURCE_PREFIX "/i18n"  # Wichtig: Der Pfad im Ressourcen-System
)

# Ressourcen brauchen Qt::Core
target_link_libraries(sival-ressource PUBLIC
    Qt::Core
)
