# Trichechus Install Profile [![Build Status](https://travis-ci.org/ManatiCR/trichechus.svg?branch=8.x-1.x)](https://travis-ci.org/ManatiCR/trichechus)

A base Drupal install profile to scaffold Manati projects.

## How to use it?

On any Drupal project, add trichechus to your build:

```php
composer require manaticr/trichechus
```

## What does it contain?

### Modules

This project contains several modules commonly used in Manati projects:

- admin_toolbar
- admin_toolbar_tools
- analytics
- better_exposed_filters
- components
- config_split
- ctools
- default_content_deploy
- devel
- dropzonejs
- entity_embed
- environment_indicator
- focal_point
- honeypot
- image_style_quality
- inline_entity_form
- layout_builder_browser
- layout_builder_modal
- layout_builder_restrictions
- media_entity_browser
- media_entity_facebook
- media_entity_twitter
- metatag
- paragraphs
- pathauto
- quicklink
- rabbit_hole
- recaptcha
- redirect
- redis
- retina_images
- search_api_solr
- seckit
- shs
- smtp
- stage_file_proxy
- svg_image
- twig_tweak
- xmlsitemap

### Themes

Includes:

- emulsify-drupal

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

```php
$config['config_split.config_split.dev']['status'] = TRUE;
```

### Environment Indicator

You need to enable environment indicator wherever you want to use it by adding these lines of code in settings.php:

```php
$config['environment_indicator.indicator']['bg_color'] = '#FF0100';
$config['environment_indicator.indicator']['fg_color'] = '#FFFFFF';
$config['environment_indicator.indicator']['name'] = 'Live';
```

### Default Content Deploy

You need to create a folder called `content` in the root of the project and then we need to let Drupal to know the location of the folder:

```php
$settings['default_content_deploy_content_directory'] = '../content';
```

### DropzoneJS

This profile includes dropzonejs library; however, it's installed under vendor/enyo until https://github.com/ManatiCR/trichechus/issues/1 gets fixed. It's your responsability to move it to the right folder (web/libraries/dropzone). If your project is using https://github.com/kporras07/composer-symlinks you could do it with a symlink like this:

```php
  "extra":
    "symlinks": {
      "vendor/enyo/dropzone": "web/libraries/dropzone"
    }
  }
```
