# Trichechus Install Profile

A base Drupal install profile to scaffold Manati projects.

## How to use it?

On any Drupal project, add trichechus to your build:
```
composer require manaticr/trichechus
```

## What does it contain?

### Modules

This project contains several modules commonly used in Manati projects:

- pathauto
- devel
- admin_toolbar
- admin_toolbar_tools
- rabbit_hole
- twig_tweak
- svg_image
- config_split
- xmlsitemap
- metatag
- seckit
- inline_entity_form
- paragraphs
- environment_indicator
- default_content_deploy
- video_embed_field
- recaptcha
- ctools
- honeypot
- better_exposed_filters
- dropzonejs
- stage_file_proxy
- focal_point
- entity_embed

### Themes

Includes:

- material_admin

In the near future, a base theme will be included so that you can bootstrap your theming faster.

### Basic configuration

We have already done some basic configuration:

- media module (including wysiwyg entity embed)
- config_split
- some other modules basic config

## Configuration Management

You are expected to export all your site configuration and keep it in your normal configuration workflow.
This profile already have a config split named "dev" so you can separate your dev modules and config. It's disabled by default.

## Extra Steps

In order to use some of the provided config, you need to do some extra steps:
### Configuration Split

You need to enable the split wherever it's necessary by using this line of code in settings.php:
```
$config['config_split.config_split.dev']['status'] = TRUE;
```

### Environment Indicator

You need to enable environment indicator wherever you want to use it by adding these lines of code in settings.php:
```
$config['environment_indicator.indicator']['bg_color'] = '#FF0100';
$config['environment_indicator.indicator']['fg_color'] = '#FFFFFF';
$config['environment_indicator.indicator']['name'] = 'Live';
```

### DropzoneJS

This profile includes dropzonejs library; however, it's installed under vendor/enyo until https://github.com/ManatiCR/trichechus/issues/1 gets fixed. It's your responsability to move it to the right folder (web/libraries/dropzone). If your project is using https://github.com/kporras07/composer-symlinks you could do it with a symlink like this:
```
  "extra":
    "symlinks": {
      "vendor/enyo/dropzone": "web/libraries/dropzone"
    }
  }
```
