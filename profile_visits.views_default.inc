<?php

function profile_visits_views_default_views() {
  $view = new view;
  $view->name = 'profile_visits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Profile Visits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Profile Visits';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access own visits';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'You have no visits yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Users visits: Uid of the host */
  $handler->display->display_options['relationships']['uid_host']['id'] = 'uid_host';
  $handler->display->display_options['relationships']['uid_host']['table'] = 'users_visits';
  $handler->display->display_options['relationships']['uid_host']['field'] = 'uid_host';
  $handler->display->display_options['relationships']['uid_host']['label'] = 'Host';
  $handler->display->display_options['relationships']['uid_host']['required'] = 1;
  /* Relationship: Users visits: Uid of the visitor */
  $handler->display->display_options['relationships']['uid_visitor']['id'] = 'uid_visitor';
  $handler->display->display_options['relationships']['uid_visitor']['table'] = 'users_visits';
  $handler->display->display_options['relationships']['uid_visitor']['field'] = 'uid_visitor';
  $handler->display->display_options['relationships']['uid_visitor']['label'] = 'Visitor';
  $handler->display->display_options['relationships']['uid_visitor']['required'] = 1;
  /* Field: Users visits: Does host user knows about visit */
  $handler->display->display_options['fields']['host_read']['id'] = 'host_read';
  $handler->display->display_options['fields']['host_read']['table'] = 'users_visits';
  $handler->display->display_options['fields']['host_read']['field'] = 'host_read';
  $handler->display->display_options['fields']['host_read']['label'] = '';
  $handler->display->display_options['fields']['host_read']['exclude'] = TRUE;
  $handler->display->display_options['fields']['host_read']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['external'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['host_read']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['host_read']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['host_read']['alter']['html'] = 0;
  $handler->display->display_options['fields']['host_read']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['host_read']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['host_read']['hide_empty'] = 0;
  $handler->display->display_options['fields']['host_read']['empty_zero'] = 0;
  $handler->display->display_options['fields']['host_read']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['host_read']['not'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid_visitor';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Users visits: Visited date */
  $handler->display->display_options['fields']['visited_at']['id'] = 'visited_at';
  $handler->display->display_options['fields']['visited_at']['table'] = 'users_visits';
  $handler->display->display_options['fields']['visited_at']['field'] = 'visited_at';
  $handler->display->display_options['fields']['visited_at']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['external'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['visited_at']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['visited_at']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['visited_at']['alter']['html'] = 0;
  $handler->display->display_options['fields']['visited_at']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['visited_at']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['visited_at']['hide_empty'] = 0;
  $handler->display->display_options['fields']['visited_at']['empty_zero'] = 0;
  $handler->display->display_options['fields']['visited_at']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['visited_at']['date_format'] = 'time ago';
  /* Sort criterion: Users visits: Visited date */
  $handler->display->display_options['sorts']['visited_at']['id'] = 'visited_at';
  $handler->display->display_options['sorts']['visited_at']['table'] = 'users_visits';
  $handler->display->display_options['sorts']['visited_at']['field'] = 'visited_at';
  $handler->display->display_options['sorts']['visited_at']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid_host';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/visits';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Visits';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;

  return array($view->name => $view);
}
